# OpenBeacon
An open source synchronized beacon light for experimental aircraft.

# Motivation
The goal is to develop an open source beacon light pcb that can be used wherever no form one is needed to exchange costly COTS components with self-made hardware.

# Modularity
OpenBeacon aims to me modular, so that users can choose between a light and low beacon that can be stacked higher if more vibisi... visi...vibilisity.... if more light is desired.

# Synchronized
OpenBeacon uses an open-collector Sync-Bus were all participants are equals. Everytime a bus participant finishes its blink pattern it pulls the sync bus low to reset all blink patterns. In theory all patterns last three seconds but unnoticeably tiny differences in timing within the participants cause one device to trigger a sync first. That way, no matter how many devices are connected to the bus, they will all synchronize once each cycle.
