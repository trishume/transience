require "dbus"
require "pry"

def randDot
  [rand(1920),rand(1080),rand(250),rand(250),rand(250)]
end

def randDots(n)
  (1..n).map { randDot }
end

sessbus = DBus.session_bus
service = sessbus["ca.thume.transience"]
obj = service.object "/ca/thume/transience/screensurface"
obj.introspect
int = obj["ca.thume.transience.screensurface"]
puts "Successfully set up!" if int

binding.pry
