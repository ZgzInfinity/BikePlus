##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=BikePlus
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Gord/Desktop/Prueba
ProjectPath            :=C:/Users/Gord/Desktop/Prueba/BikePlus
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Gord
Date                   :=07/08/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="BikePlus.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/BikePlus_BikePlus.cpp$(ObjectSuffix) $(IntermediateDirectory)/Usuario_Bizi-usuario.cc$(ObjectSuffix) $(IntermediateDirectory)/Estacion_Bizi-estacion.cc$(ObjectSuffix) $(IntermediateDirectory)/Uso_Bizi-uso.cc$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/BikePlus_BikePlus.cpp$(ObjectSuffix): BikePlus/BikePlus.cpp $(IntermediateDirectory)/BikePlus_BikePlus.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gord/Desktop/Prueba/BikePlus/BikePlus/BikePlus.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BikePlus_BikePlus.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BikePlus_BikePlus.cpp$(DependSuffix): BikePlus/BikePlus.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BikePlus_BikePlus.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BikePlus_BikePlus.cpp$(DependSuffix) -MM BikePlus/BikePlus.cpp

$(IntermediateDirectory)/BikePlus_BikePlus.cpp$(PreprocessSuffix): BikePlus/BikePlus.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BikePlus_BikePlus.cpp$(PreprocessSuffix) BikePlus/BikePlus.cpp

$(IntermediateDirectory)/Usuario_Bizi-usuario.cc$(ObjectSuffix): Usuario/Bizi-usuario.cc $(IntermediateDirectory)/Usuario_Bizi-usuario.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gord/Desktop/Prueba/BikePlus/Usuario/Bizi-usuario.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Usuario_Bizi-usuario.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Usuario_Bizi-usuario.cc$(DependSuffix): Usuario/Bizi-usuario.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Usuario_Bizi-usuario.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/Usuario_Bizi-usuario.cc$(DependSuffix) -MM Usuario/Bizi-usuario.cc

$(IntermediateDirectory)/Usuario_Bizi-usuario.cc$(PreprocessSuffix): Usuario/Bizi-usuario.cc
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Usuario_Bizi-usuario.cc$(PreprocessSuffix) Usuario/Bizi-usuario.cc

$(IntermediateDirectory)/Estacion_Bizi-estacion.cc$(ObjectSuffix): Estacion/Bizi-estacion.cc $(IntermediateDirectory)/Estacion_Bizi-estacion.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gord/Desktop/Prueba/BikePlus/Estacion/Bizi-estacion.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Estacion_Bizi-estacion.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Estacion_Bizi-estacion.cc$(DependSuffix): Estacion/Bizi-estacion.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Estacion_Bizi-estacion.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/Estacion_Bizi-estacion.cc$(DependSuffix) -MM Estacion/Bizi-estacion.cc

$(IntermediateDirectory)/Estacion_Bizi-estacion.cc$(PreprocessSuffix): Estacion/Bizi-estacion.cc
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Estacion_Bizi-estacion.cc$(PreprocessSuffix) Estacion/Bizi-estacion.cc

$(IntermediateDirectory)/Uso_Bizi-uso.cc$(ObjectSuffix): Uso/Bizi-uso.cc $(IntermediateDirectory)/Uso_Bizi-uso.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Gord/Desktop/Prueba/BikePlus/Uso/Bizi-uso.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Uso_Bizi-uso.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Uso_Bizi-uso.cc$(DependSuffix): Uso/Bizi-uso.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Uso_Bizi-uso.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/Uso_Bizi-uso.cc$(DependSuffix) -MM Uso/Bizi-uso.cc

$(IntermediateDirectory)/Uso_Bizi-uso.cc$(PreprocessSuffix): Uso/Bizi-uso.cc
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Uso_Bizi-uso.cc$(PreprocessSuffix) Uso/Bizi-uso.cc


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


