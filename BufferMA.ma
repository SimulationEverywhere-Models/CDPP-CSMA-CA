[top]
components : Buffer@BufferType 
out : job_out 
in : msg_in done_in 
Link : msg_in msg_in@Buffer
Link : done_in done_in@Buffer
Link : job_out@Buffer job_out

[Buffer]
preparation : 00:00:10:000


