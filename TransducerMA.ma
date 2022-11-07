[top]
components : T@TransducerType 
in : msg_gen msg_sent 
out : throughput latency
Link : msg_gen msg_gen@T
Link : msg_sent msg_sent@T
Link : throughput@T throughput
Link : latency@T latency

[Transducer]


