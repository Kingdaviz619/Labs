Virtual Cybersecurity Lab: Installation and Configuration Guide

1. Installing VMware Workstation Pro

Overview

VMware Workstation Pro is a desktop virtualization platform that allows multiple operating systems to run as virtual machines on a single physical computer. It provides an isolated environment for building and testing network infrastructure, practicing system administration, and conducting authorized cybersecurity exercises.

Installation Procedure

For this project, VMware Workstation Pro was installed on a Linux Mint host.

1. Visit the official VMware website and navigate to the VMware Workstation download page.
2. Download the installation package compatible with the host operating system.
3. Locate the downloaded installer.
4. Follow the installation instructions for the downloaded package.
5. Complete the installation and launch VMware Workstation.
6. Verify that the application launches successfully and that the virtualization environment is ready for use.

Note: Installation procedures vary depending on the host operating system and installer format. Refer to the official documentation for the appropriate procedure.

Documentation evidence to add:



---

2. Creating and Configuring the OPNsense Virtual Machine

Overview

OPNsense serves as the virtual firewall and router for the lab. It manages communication between designated virtual networks and provides a central point for configuring network access and security policies.

Procedure

1. Download the appropriate OPNsense installation image from the official OPNsense website.
2. Open VMware Workstation and create a new virtual machine.
3. Select the downloaded installation image as the virtual machine's installation media.
4. Assign appropriate virtual hardware resources, including CPU, memory, and storage.
5. Configure the virtual network adapters according to the intended network topology.
6. Start the virtual machine and follow the OPNsense installation procedure.
7. Complete the installation and configure the required network interfaces.
8. Assign the WAN and LAN interfaces according to the lab design.
9. Configure the LAN addressing scheme and enable DHCP where required.
10. Verify the interface assignments and access the OPNsense web administration interface.

Configuration considerations

- Keep the lab's internal networks separate from networks that should not be accessible to test systems.
- Ensure that each virtual network has a clearly defined purpose.
- Avoid overlapping IP address ranges.
- Record the IP address, subnet mask, and intended function of each interface.

Documentation evidence to add:

- Screenshot of the OPNsense VM hardware settings.
- Screenshot of its virtual network adapters.
- Screenshot of the interface assignments.
- Screenshot of the firewall dashboard.

---

3. Installing Kali Linux, Ubuntu Server, and Windows Virtual Machines

Overview

Additional virtual machines provide the systems needed to practice security testing, server administration, endpoint monitoring, and Windows domain management.

The lab may include Kali Linux, Ubuntu Server, Windows 10, Windows Server, and other intentionally vulnerable systems used for authorized testing.

Procedure

1. Obtain the appropriate ISO images from the respective operating systems' official distribution sources.
2. Create a separate virtual machine for each operating system.
3. Attach the appropriate ISO image to each VM.
4. Allocate CPU cores, RAM, and virtual disk capacity according to the system's requirements and the host computer's available resources.
5. Configure each VM's network adapter to connect to the intended virtual network.
6. Start each VM and complete its operating system installation.
7. Install the necessary guest integration tools where supported.
8. Verify that each operating system boots correctly.
9. Record each VM's specifications and intended role in the lab.

Virtual machine inventory

Document the actual configuration of each system.

Virtual machine| Purpose| RAM| Virtual disk| Network
OPNsense| Firewall and routing| To be documented| To be documented| WAN/LAN
Kali Linux| Security testing| To be documented| To be documented| Lab network
Ubuntu Server| Server administration and monitoring| To be documented| To be documented| Server network
Windows 10| Endpoint security testing| To be documented| To be documented| Client network
Windows Server| Active Directory and domain services| To be documented| To be documented| Domain network

Add any additional virtual machines you have configured.

---

4. Configuring IP Addresses and Virtual Networks

Overview

Correct IP addressing and virtual network configuration allow the lab systems to communicate according to the intended network design.

The lab uses VMware virtual networks to organize communication between the firewall, servers, clients, and security-testing systems.

Procedure

1. Identify the virtual networks required by the lab.
2. Configure the corresponding VMware virtual network adapters.
3. Assign each virtual machine to its designated network.
4. Configure OPNsense interfaces with the appropriate IP addresses and subnet masks.
5. Configure DHCP on the networks where dynamic addressing is required.
6. Assign static IP addresses to systems that require predictable addressing, such as servers and network infrastructure.
7. Configure the appropriate default gateway and DNS settings on each system.
8. Verify that IP addresses do not conflict and that subnets are correctly defined.

Configuration records

For each virtual network, document:

- Network name and VMware network identifier.
- Network address and subnet mask.
- Gateway address.
- DHCP address range, if applicable.
- Connected virtual machines.
- Intended purpose.

Important: The addressing scheme must be consistent across the lab. A system's IP address, subnet mask, gateway, and DNS configuration should match the network to which it is connected.

---

5. Connecting Virtual Machines Through OPNsense

Overview

OPNsense provides routing and firewall services for the virtual lab. Configuring the virtual machines to use the appropriate OPNsense interfaces allows traffic to be routed between designated networks according to the configured firewall rules.

Procedure

1. Confirm that the required VMware virtual networks have been created.
2. Connect the OPNsense virtual network adapters to their intended networks.
3. Connect each client and server VM to its designated network.
4. Configure the appropriate IP address, subnet mask, default gateway, and DNS settings on each guest.
5. Confirm that the OPNsense interfaces have the expected addresses and are operational.
6. Review the firewall rules governing traffic between the networks.
7. Configure only the rules required for the intended lab activities.
8. Test communication between systems on the same subnet and, where permitted, between different subnets.
9. Review the firewall logs when traffic is blocked unexpectedly.

Security considerations

- Keep intentionally vulnerable systems on isolated lab networks.
- Do not expose vulnerable VMs directly to the public internet.
- Restrict traffic between networks according to the lab's requirements.
- Document any temporary firewall changes and restore the intended security configuration after testing.

---

6. Testing Connectivity Between Virtual Machines

Overview

Connectivity testing confirms that IP addressing, virtual network assignments, routing, and firewall rules are working as intended.

Procedure

Step 1: Verify IP configuration

On Linux systems, use the following commands to inspect interface addresses and routing information:

ip addr
ip route

On Windows systems, run:

ipconfig /all
route print

Step 2: Test local connectivity

Use "ping" to test connectivity to the relevant gateway or another system on the same network.

Example:

ping <gateway-ip-address>

Step 3: Test connectivity between virtual machines

From one VM, test the address of another VM that should be reachable.

ping <destination-ip-address>

Step 4: Verify routing

On Linux, inspect the routing table:

ip route

On Windows, inspect the routing table:

route print

Step 5: Investigate failed connections

If connectivity fails, check:

- Whether both VMs are connected to the correct VMware networks.
- Whether the IP addresses and subnet masks are correct.
- Whether the destination is reachable through the configured gateway.
- Whether the OPNsense firewall rules permit the traffic.
- Whether the destination host's firewall blocks the connection.

Important: A failed ping does not always indicate a network failure. A host firewall may block ICMP traffic while allowing other services. Interpret the results alongside other relevant tests.

Results

Record the source VM, destination VM, expected outcome, observed outcome, and any corrective action taken.

Source| Destination| Expected result| Observed result
Kali Linux| OPNsense LAN interface| Reachable| To be documented
Ubuntu Server| OPNsense LAN interface| Reachable| To be documented
Windows 10| Windows Server| Depends on network and firewall configuration| To be documented
Kali Linux| Windows 10| Depends on network and firewall configuration| To be documented

Replace the placeholders with your actual test results.

---

7. Troubleshooting and Verification

Overview

Troubleshooting involves identifying and resolving configuration problems that prevent virtual machines, network interfaces, or services from operating as intended.

Common issues and diagnostic approaches

Issue 1: A virtual machine cannot obtain an IP address

Possible causes:

- DHCP is disabled or incorrectly configured.
- The VM is connected to the wrong virtual network.
- The DHCP address pool is exhausted.
- The network interface is not operational.

Diagnostic approach:

1. Inspect the VM's network adapter settings.
2. Check its current IP configuration.
3. Verify that the correct DHCP service is enabled.
4. Review the DHCP configuration and logs.
5. Renew the address where appropriate and test again.

Issue 2: A VM cannot reach its default gateway

Possible causes:

- An incorrect IP address or subnet mask.
- A mismatched virtual network assignment.
- An unavailable or incorrectly configured gateway.
- A firewall or interface configuration problem.

Diagnostic approach:

1. Inspect the guest's IP configuration and routing table.
2. Confirm the gateway's address and subnet.
3. Verify the VM's VMware network assignment.
4. Check the relevant OPNsense interface.
5. Test connectivity again after correcting any identified issue.

Issue 3: Virtual machines on different networks cannot communicate

Possible causes:

- Incorrect routing.
- Firewall rules blocking traffic.
- Incorrect gateway configuration.
- Overlapping or inconsistent subnets.

Diagnostic approach:

1. Verify the source and destination IP configurations.
2. Inspect the routing table on the source VM.
3. Confirm that OPNsense has the required interfaces and routes.
4. Review the applicable firewall rules and logs.
5. Retest the connection.

Issue 4: A virtual machine has no internet access

Possible causes:

- An incorrect WAN configuration.
- Missing or incorrect gateway settings.
- DNS resolution problems.
- Missing firewall permissions.
- Incorrect VMware networking or upstream connectivity.

Diagnostic approach:

1. Confirm that the host computer has internet access.
2. Inspect the OPNsense WAN status.
3. Test connectivity to an external IP address from an appropriate lab system.
4. Test DNS resolution separately.
5. Review firewall and outbound NAT configuration where applicable.

Troubleshooting documentation

For every significant issue encountered, record:

- Problem: What failed?
- Symptoms: What did you observe?
- Investigation: Which commands, logs, or settings did you inspect?
- Root cause: What caused the problem, if established?
- Solution: What changes resolved it?
- Verification: How did you confirm the fix worked?
- Lessons learned: What will you do differently next time?

This makes the documentation useful to anyone trying to understand or reproduce your lab.

---

Conclusion

This virtual cybersecurity lab provides an environment for practicing networking, firewall administration, server configuration, endpoint monitoring, and authorized security testing.

The documentation should evolve alongside the lab. Screenshots, configuration examples, commands, troubleshooting records, and verified test results should be added as the relevant procedures are completed.

Related article: https://medium.com/@kingdaviz619/building-my-first-virtual-cybersecurity-lab-8-gb-ram-vmware-networking-and-a-firewall-problem-e296cf7bbec0