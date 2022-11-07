[Top]
components : Med@MeduimType TR1@TxRxControllerType TR2@TxRxControllerType TR3@TxRxControllerType 
out : msgSent1 msgSent2 msgSent3 done1 done2 done3 debug1 debug2 debug3
in : dataIn1 dataIn2 dataIn3
Link : send@TR1 in1@Med
Link : send@TR2 in2@Med
Link : send@TR3 in3@Med
Link : forward1@Med receive@TR1
Link : forward2@Med receive@TR2
Link : forward3@Med receive@TR3
Link : busy1@Med busy@TR1
Link : busy2@Med busy@TR2
Link : busy3@Med busy@TR3
Link : free1@Med free@TR1
Link : free2@Med free@TR2
Link : free3@Med free@TR3
Link : dataIn1 dataIn@TR1 
Link : dataIn2 dataIn@TR2 
Link : dataIn3 dataIn@TR3
Link : msgSent@TR1 msgSent1
Link : msgSent@TR2 msgSent2
Link : msgSent@TR3 msgSent3
Link : done@TR1 done1
Link : done@TR2 done2
Link : done@TR3 done3
Link : debug@TR1 debug1
Link : debug@TR2 debug2
Link : debug@TR3 debug3
[Med]


[TR1]

[TR2]


