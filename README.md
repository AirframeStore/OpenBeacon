![OpenBeacon logo](/logo/openBeacon_airframe_banner.png)

# OpenBeacon
An open source synchronized beacon light for experimental aircraft.

# Motivation
The goal is to develop an open source beacon light pcb that can be used wherever no "Form 1" is needed to exchange costly COTS components with self-made hardware.

# Modularity
OpenBeacon aims to me modular, so that users can choose between a light and low beacon that can be stacked higher if more vibisi... visi...vibilisity.... if more light is desired.

# Synchronized
OpenBeacon uses an open-collector Sync-Bus were all participants are equals. Everytime a bus participant finishes its blink pattern it pulls the sync bus low to reset all blink patterns. In theory all OpenBeacon frames last three seconds but unnoticeably tiny differences in timing within the participants cause one device to trigger a sync first. That way, no matter how many devices are connected to the bus, they will all synchronize once each cycle.

## Programmable Blink Cycles
The following are recommendations but with OpenBeacon, individual blink patterns can be programmed into each device.
### Anti Collision Lights (ACL)
ACLs, often white at the wing tips, rear, top and/or bottom give short flashes. They usually blink in a "blink-blink pause" sequence that repeats every 1.5 seconds. This pattern fits twice in a standard OpenBeacon frame.
### Beacons
Beacons, most often red lights on the top or bottom of the fuselage, usually have a longer on-time than ACLs. They can blink in sync or shifted by half a phase from the ACLs. They usually have a 25-50% on-time over a OpenBeacon half-frame.
### WigWag Blinking Lights
WigWag Lights are often used in forward pointing lights to increase heads-on visibility with a bright white light. The WigWag pattern (lights jumping left to right) further increase visibility. Two WigWag lights usually turn on back and forth each at 50% of a full OpenBeacon Frame, so that the Light jumps to the other side every 1.5 seconds.
