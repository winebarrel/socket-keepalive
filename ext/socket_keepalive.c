#include "socket_keepalive.h"

static VALUE rb_mSocketKeepalive;
static VALUE rb_eSocketKeepaliveError;

/* get SO_KEEPALIVE */
static VALUE rb_sk_get_keepalive(VALUE self, VALUE vSockfd) {
  int sockfd, optval, rv;
  socklen_t optlen;

  sockfd = NUM2INT(vSockfd);

  optlen = sizeof(optval);
  rv = getsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, (void*) &optval, &optlen);

  if (rv != 0) { 
    rb_raise(rb_eSocketKeepaliveError, "%s", strerror(errno));
  }

  return(optval ? Qtrue : Qfalse);
}

/* set SO_KEEPALIVE */
static VALUE rb_sk_set_keepalive(VALUE self, VALUE vSockfd, VALUE vOptval) {
  int sockfd, optval, rv;
  const char *classname;

  sockfd = NUM2INT(vSockfd);

  switch (TYPE(vOptval)) {
  case T_TRUE:
    optval = 1;
    break;
  case T_FALSE:
    optval = 0;
    break;
  default:
    classname = rb_class2name(CLASS_OF(vOptval));
    rb_raise(rb_eTypeError, "wrong argument type %s (expected TrueClass or FalseClass)", classname);
    break;
  }

  rv = setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, (void*) &optval, sizeof(optval));

  if (rv != 0) { 
    rb_raise(rb_eSocketKeepaliveError, "%s", strerror(errno));
  }

  return Qnil;
}

/* get TCP_KEEPIDLE */
static VALUE rb_sk_get_keepidle(VALUE self, VALUE vSockfd) {
#ifdef TCP_KEEPIDLE
  int sockfd, optval, rv;
  socklen_t optlen;

  sockfd = NUM2INT(vSockfd);

  optlen = sizeof(optval);
  rv = getsockopt(sockfd, IPPROTO_TCP, TCP_KEEPIDLE, (void*) &optval, &optlen);

  if (rv != 0) { 
    rb_raise(rb_eSocketKeepaliveError, "%s", strerror(errno));
  }

  return INT2NUM(optval);
#else
  return Qnil;
#endif
}

/* set TCP_KEEPIDLE */
static VALUE rb_sk_set_keepidle(VALUE self, VALUE vSockfd, VALUE vOptval) {
#ifdef TCP_KEEPIDLE
  int sockfd, optval, rv;

  sockfd = NUM2INT(vSockfd);
  sockfd = NUM2INT(vSockfd);

  rv = setsockopt(sockfd, IPPROTO_TCP, TCP_KEEPIDLE, (void*) &optval, sizeof(optval));

  if (rv != 0) { 
    rb_raise(rb_eSocketKeepaliveError, "%s", strerror(errno));
  }
#endif

  return Qnil;
}

/* get TCP_KEEPINTVL */
static VALUE rb_sk_get_keepintvl(VALUE self, VALUE vSockfd) {
#ifdef TCP_KEEPINTVL
  int sockfd, optval, rv;
  socklen_t optlen;

  sockfd = NUM2INT(vSockfd);

  optlen = sizeof(optval);
  rv = getsockopt(sockfd, IPPROTO_TCP, TCP_KEEPINTVL, (void*) &optval, &optlen);

  if (rv != 0) { 
    rb_raise(rb_eSocketKeepaliveError, "%s", strerror(errno));
  }

  return INT2NUM(optval);
#else
  return Qnil;
#endif
}

/* set TCP_KEEPINTVL */
static VALUE rb_sk_set_keepintvl(VALUE self, VALUE vSockfd, VALUE vOptval) {
#ifdef TCP_KEEPINTVL
  int sockfd, optval, rv;

  sockfd = NUM2INT(vSockfd);
  sockfd = NUM2INT(vSockfd);

  rv = setsockopt(sockfd, IPPROTO_TCP, TCP_KEEPINTVL, (void*) &optval, sizeof(optval));

  if (rv != 0) { 
    rb_raise(rb_eSocketKeepaliveError, "%s", strerror(errno));
  }
#endif

  return Qnil;
}

/* get TCP_KEEPCNT */
static VALUE rb_sk_get_keepcnt(VALUE self, VALUE vSockfd) {
#ifdef TCP_KEEPCNT
  int sockfd, optval, rv;
  socklen_t optlen;

  sockfd = NUM2INT(vSockfd);

  optlen = sizeof(optval);
  rv = getsockopt(sockfd, IPPROTO_TCP, TCP_KEEPCNT, (void*) &optval, &optlen);

  if (rv != 0) { 
    rb_raise(rb_eSocketKeepaliveError, "%s", strerror(errno));
  }

  return INT2NUM(optval);
#else
  return Qnil;
#endif
}

/* set TCP_KEEPCNT */
static VALUE rb_sk_set_keepcnt(VALUE self, VALUE vSockfd, VALUE vOptval) {
#ifdef TCP_KEEPCNT
  int sockfd, optval, rv;

  sockfd = NUM2INT(vSockfd);
  sockfd = NUM2INT(vSockfd);

  rv = setsockopt(sockfd, IPPROTO_TCP, TCP_KEEPCNT, (void*) &optval, sizeof(optval));

  if (rv != 0) { 
    rb_raise(rb_eSocketKeepaliveError, "%s", strerror(errno));
  }

  return Qnil;
#endif
}


void Init_socket_keepalive() {
  rb_mSocketKeepalive = rb_define_module("SocketKeepalive");
  rb_eSocketKeepaliveError = rb_define_class_under(rb_mSocketKeepalive, "Error", rb_eStandardError);

  // TCP_KEEPIDLE
  rb_define_module_function(rb_mSocketKeepalive, "get_keepalive", rb_sk_get_keepalive, 0);
  rb_define_module_function(rb_mSocketKeepalive, "set_keepalive", rb_sk_set_keepalive, 2);

  // TCP_KEEPIDLE
  rb_define_module_function(rb_mSocketKeepalive, "get_keepidle", rb_sk_get_keepidle, 0);
  rb_define_module_function(rb_mSocketKeepalive, "set_keepidle", rb_sk_set_keepidle, 2);

  // TCP_KEEPINTVL
  rb_define_module_function(rb_mSocketKeepalive, "get_keepintvl", rb_sk_get_keepintvl, 0);
  rb_define_module_function(rb_mSocketKeepalive, "set_keepintvl", rb_sk_set_keepintvl, 2);

  // TCP_KEEPCNT
  rb_define_module_function(rb_mSocketKeepalive, "get_keepcnt", rb_sk_get_keepcnt, 0);
  rb_define_module_function(rb_mSocketKeepalive, "set_keepcnt", rb_sk_set_keepcnt, 2);
}
