
#Simulation Create Autogens
SimCreateAutogenIncludes= ${shell $(SimCreate)/Script/scTypes.pl list_include $(SimCreate)}
SimCreateAutogenSources=  ${shell $(SimCreate)/Script/scTypes.pl list_source  $(SimCreate)}
SimCreateObjFromAutogen=  ${shell $(SimCreate)/Script/scTypes.pl list_obj     $(SimCreate)}

#Simulation Execute Autogens
SimExecuteAutogenIncludes= ${shell $(SimExecute)/Script/seTypes.pl list_include $(SimExecute)}
SimExecuteAutogenSources=  ${shell $(SimExecute)/Script/seTypes.pl list_source  $(SimExecute)}
SimExecuteObjFromAutogen=  ${shell $(SimExecute)/Script/seTypes.pl list_obj     $(SimExecute)}

AllAutogenIncludes=           $(SimCreateAutogenIncludes)
AllAutogenIncludes+=          $(SimExecuteAutogenIncludes)
