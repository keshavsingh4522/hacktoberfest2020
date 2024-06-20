import subprocess
import optparse
import re
def mac_changer(iface, mac):
    print("[*]changing mac address for " + iface + " to " + mac)
    subprocess.call(["ifconfig", iface, "down"])
    subprocess.call(["ifconfig", iface, "hw", "ether", mac])
    subprocess.call(["ifconfig", iface, "up"])
    print("[*]mac address of " + iface + " changed to " + mac)
def get_arguments():
    parser = optparse.OptionParser()
    parser.add_option("-i", "--interface", dest="iface", help="interface")
    parser.add_option("-m", "--mac", dest="mac", help="new mac address")
    (arguments,options) = parser.parse_args()
    if not arguments.iface:
        parser.error("please specify interface,use -help to know more")
    elif not arguments.mac:
        parser.error("please specify mac ,use -help to know more")
    return arguments
def current_mac(interface):
    ifconfig_result = subprocess.check_output(["ifconfig", interface]).decode("utf-8")
    curr_mac = re.search(r"\w\w:\w\w:\w\w:\w\w:\w\w:\w\w", ifconfig_result)
    if not curr_mac:
        print("[*]sorry unable to get your mac adress")
    else:
        print("[*]your current mac is " + curr_mac[0])
        return curr_mac[0]


arguments = get_arguments()
curr_mac = current_mac(arguments.iface)
mac_changer(arguments.iface, arguments.mac)
curr_mac = current_mac(arguments.iface)
if curr_mac == arguments.mac:
    print("[*]mac changed successfully to the desired mac")
else:
    print("sorry we are unable to change the mac address")
