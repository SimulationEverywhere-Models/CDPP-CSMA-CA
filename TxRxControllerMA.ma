[Top]
components : TxRx@TxRxControllerType 
out : send done msgSent 
in : free busy receive dataIn 

Link : free free@TxRx
Link : busy busy@TxRx
Link : receive receive@TxRx
Link : dataIn dataIn@TxRx
Link : msgSent@TxRx msgSent
Link : done@TxRx done
Link : send@TxRx send