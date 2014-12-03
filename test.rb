require "dbus"
require "pry"

sessbus = DBus.session_bus
service = sessbus["ca.thume.transience"]
obj = service.object "/ca/thume/transience/hintmanager"
obj.introspect
int = obj["ca.thume.transience.hintmanager"]
puts "Successfully set up!" if int

binding.pry
