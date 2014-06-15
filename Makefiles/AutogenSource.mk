
#Simulation Execute Autogens
SimExecuteAutogenIncludes= ${shell $(SimExecute)/Script/seTypes.pl list_include $(SimExecute)}
SimExecuteAutogenSources=  ${shell $(SimExecute)/Script/seTypes.pl list_source  $(SimExecute)}
SimExecuteObjFromAutogen=  ${shell $(SimExecute)/Script/seTypes.pl list_obj     $(SimExecute)}

AllAutogenIncludes=           $(SimCreateAutogenIncludes)
AllAutogenIncludes+=          $(SimExecuteAutogenIncludes)
