Date: 13/9/2012
Name: Moe-Heli 
Version 1 



In the simulator implementation, we have mapped the micro second values to milliseconds. This is because inbuilt CD++ Time( ) function defined in time.h defines time in the following format;
 
Time (hours: minutes: seconds: milliseconds)

The average packet size is in the range of 100 bytes and 1000 bytes, which are equivalent to 15 ?S and 150 ?S message lengths (based on IEEE 802.11g average throughput data rate). To overcome this issue, we have simulated the time in the simulator supported format. However we have accounted it when calculating the throughput and latency at the transducer. 
The generated message is at least a 7 digit integer, which is a multiplexed output of three integer values which represent; destination node, message ID and length. In this scenario, we have simulated the CSMA/CA protocol for maximum of 10 wireless nodes communicating over shared medium (frequency channel).