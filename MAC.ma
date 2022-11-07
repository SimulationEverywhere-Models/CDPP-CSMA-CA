[Top]
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

