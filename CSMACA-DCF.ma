[Top]
components : M@MeduimType Node1 Node2 Node3 
in : 
out : latency1 latency2 latency3 throughput1 throughput2 throughput3 debug1 debug2 debug3 free busy

debug send throughput latency
Link : free0@M free
Link : busy0@M busy
Link : debug@Node1 debug1
Link : debug@Node2 debug2
Link : debug@Node3 debug3
Link : throughput@Node1 throughput1
Link : throughput@Node2 throughput2
Link : throughput@Node3 throughput3
Link : latency@Node1 latency1
Link : latency@Node2 latency2
Link : latency@Node3 latency3
Link : send@Node1 in1@M
Link : send@Node2 in2@M
Link : send@Node3 in3@M
Link : free1@M free@Node1
Link : free2@M free@Node2
Link : free3@M free@Node3
Link : busy1@M busy@Node1
Link : busy2@M busy@Node2
Link : busy3@M busy@Node3
Link : forward1@M receive@Node1
Link : forward2@M receive@Node2
Link : forward3@M receive@Node3


[Node1]
components : MAC1 Gen1@GeneratorType T1@TransducerType 
in : busy free receive
out : debug send throughput latency

Link : busy busy@MAC1
Link : free free@MAC1
Link : receive receive@MAC1
Link : debug@MAC1 debug
Link : send@MAC1 send
Link : throughput@T1 throughput
Link : latency@T1 latency
Link : msgSent@MAC1 msg_sent@T1
Link : msgCreated@Gen1 msg_gen@T1 
Link : out@Gen1 msg_in@MAC1
[Gen1]
ME : 1
MAX : 3
[MAC1]
components : TR1@TxRxControllerType Buffer1@BufferType
in : msg_in receive busy free
out : msgSent send debug

Link : msg_in msg_in@Buffer1
Link : receive receive@TR1
Link : busy busy@TR1
Link : done@TR1 done_in@Buffer1
Link : job_out@Buffer1 dataIn@TR1
Link : free free@TR1
Link : msgSent@TR1 msgSent
Link : debug@TR1 debug
Link : send@TR1 send

[Node2]
components : MAC2 Gen2@GeneratorType T2@TransducerType 
in : busy free receive
out : debug send throughput latency

Link : busy busy@MAC2
Link : free free@MAC2
Link : receive receive@MAC2
Link : debug@MAC2 debug
Link : send@MAC2 send
Link : throughput@T2 throughput
Link : latency@T2 latency
Link : msgSent@MAC2 msg_sent@T2
Link : msgCreated@Gen2 msg_gen@T2
Link : out@Gen2 msg_in@MAC2
[Gen2]
ME : 2
MAX : 3
[MAC2]
components : TR2@TxRxControllerType Buffer2@BufferType
in : msg_in receive busy free
out : msgSent send debug

Link : msg_in msg_in@Buffer2
Link : receive receive@TR2
Link : busy busy@TR2
Link : done@TR2 done_in@Buffer2
Link : job_out@Buffer2 dataIn@TR2
Link : free free@TR2
Link : msgSent@TR2 msgSent
Link : debug@TR2 debug
Link : send@TR2 send



[Node3]
components : MAC3 Gen3@GeneratorType T3@TransducerType 
in : busy free receive
out : debug send throughput latency

Link : busy busy@MAC3
Link : free free@MAC3
Link : receive receive@MAC3
Link : debug@MAC3 debug
Link : send@MAC3 send
Link : throughput@T3 throughput
Link : latency@T3 latency
Link : msgSent@MAC3 msg_sent@T3
Link : msgCreated@Gen3 msg_gen@T3
Link : out@Gen3 msg_in@MAC3
[Gen3]
ME : 3
MAX : 3
[MAC3]
components : TR3@TxRxControllerType Buffer3@BufferType
in : msg_in receive busy free
out : msgSent send debug

Link : msg_in msg_in@Buffer3
Link : receive receive@TR3
Link : busy busy@TR3
Link : done@TR3 done_in@Buffer3
Link : job_out@Buffer3 dataIn@TR3
Link : free free@TR3
Link : msgSent@TR3 msgSent
Link : debug@TR3 debug
Link : send@TR3 send




