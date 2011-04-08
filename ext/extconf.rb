require 'mkmf'
$CFLAGS += " -Wall "
create_makefile('socket_keepalive')
