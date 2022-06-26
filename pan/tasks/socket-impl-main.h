/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * Pan - A Newsreader for Gtk+
 * Copyright (C) 2002-2006  Charles Kerr <charles@rebelbase.com>
 *
 * This file
 * Copyright (C) 2011 Heinrich Müller <henmull@src.gnome.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 */


#ifndef __SocketMAIN_h__
#define __SocketMAIN_h__

//For G_OS_WIN32 :-(
#include <glib.h>

#include <pan/general/string-view.h>
#include <pan/general/worker-pool.h>
#include "socket.h"

#ifdef HAVE_GNUTLS
  #include <gnutls/gnutls.h>
  #include "socket-impl-openssl.h"
#endif

#include <pan/data/cert-store.h>
#include "socket-impl-gio.h"


namespace pan {

#ifdef G_OS_WIN32
  extern bool has_getaddrinfo;
#endif

  class SocketCreator:
    private CertStore::Listener,
    private Socket::Creator::Listener
  {
    public:
      SocketCreator (Data&, CertStore&);
      virtual ~SocketCreator ();


    private:
      //socket::creator::Listener
      virtual void on_socket_created (const StringView& /*host*/, int /*port*/, bool /*ok*/, Socket*) override {}
      virtual void on_socket_shutdown (const StringView& /*host*/, int /*port*/, Socket*) override {}

#ifdef HAVE_GNUTLS
      // CertStore::Listener
      virtual void on_verify_cert_failed(gnutls_x509_crt_t, std::string, int) override;
      virtual void on_valid_cert_added (gnutls_x509_crt_t, std::string ) override;
#endif
      Data& data;
      CertStore & store;

    public:
      virtual void create_socket  (ServerInfo&,
                                    const Quark&,
                                    const StringView & host,
                                    int                port,
                                    WorkerPool       & threadpool,
                                    Socket::Creator::Listener * listener);

  };

}

#endif
