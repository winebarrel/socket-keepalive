Gem::Specification.new do |spec|
  spec.name              = 'socket-keepalive'
  spec.version           = '0.1.0'
  spec.summary           = 'TCP Keepalive extension for Ruby'
  spec.description       = 'TCP Keepalive extension for Ruby. see tcp(7). (Linux only)'
  spec.require_paths     = %w(lib)
  spec.files             = Dir.glob('ext/*.{c,h}') + %w(ext/extconf.rb README lib/socket/keepalive.rb)
  spec.author            = 'winebarrel'
  spec.email             = 'sgwr_dts@yahoo.co.jp'
  spec.homepage          = 'https://bitbucket.org/winebarrel/socket-keepalive'
  spec.extensions        = 'ext/extconf.rb'
  spec.has_rdoc          = false
end
