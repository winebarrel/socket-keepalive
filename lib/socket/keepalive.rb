require 'socket'
require 'socket_keepalive'

class TCPSocket
  def keepalive
    SocketKeepalive.get_keepalive(self.fileno)
  end

  def keepalive=(optval)
    SocketKeepalive.set_keepalive(self.fileno, optval)
  end

  def keepidle
    SocketKeepalive.get_keepidle(self.fileno)
  end

  def keepidle=(optval)
    SocketKeepalive.set_keepidle(self.fileno, optval)
  end

  def keepintvl
    SocketKeepalive.get_keepintvl(self.fileno)
  end

  def keepintvl=(optval)
    SocketKeepalive.set_keepintvl(self.fileno, optval)
  end

  def keepcnt
    SocketKeepalive.get_keepcnt(self.fileno)
  end

  def keepcnt=(optval)
    SocketKeepalive.set_keepcnt(self.fileno, optval)
  end
end
