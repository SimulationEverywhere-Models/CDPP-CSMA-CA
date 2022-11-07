[Top]
components : MAC Gen@GeneratorType T@TransducerType 
in : busy free receive
out : debug send throughput latency

Link : busy busy@MAC
Link : free free@MAC
Link : receive receive@MAC
Link : debug@MAC debug
Link : send@MAC send
Link : throughput@T throughput
Link : latency@T latency
Link : msgSent@MAC msg_sent@T
Link : msgCreated@Gen msg_gen@T 
Link : out@Gen msg_in@MAC
[Gen]
ME : 1
[MAC]
components : TR@TxRxControllerType Buffer@BufferType
in : msg_in receive busy free
out : msgSent send debug

Link : msg_in msg_in@Buffer
Link : receive receive@TR
Link : busy busy@TR
Link : done@TR done_in@Buffer
Link : job_out@Buffer dataIn@TR
Link : free free@TR
Link : msgSent@TR msgSent
Link : debug@TR debug
Link : send@TR send



