from RPiLogger import RPiLogger
from time import sleep

def Function(argument: int) -> None:
    RPiLogger.EnterScope("Function")
    RPiLogger.DebugVar(argument, "argument")
    argument+=100
    RPiLogger.DebugVar(argument, "argument")
    RPiLogger.LeaveScope("Function")

RPiLogger.EnterScope("")
RPiLogger.PrintScriptsInDevice()

variable: int = 10
text: str = "ala ma kota"
sensor_data: float = 10.2
ids: list = [1,2,3,4,5]

RPiLogger.LogVar(variable)
RPiLogger.LogVar(text)
RPiLogger.LogVar(sensor_data)
RPiLogger.LogVar(ids)

try:
    run: bool = True
    while(run):
        # Some operations ...
        RPiLogger.Print("Recieved data from sensor")
        RPiLogger.Warning("Temerature is to high!")
        RPiLogger.Message("Recieved TCP packet")
        
        RPiLogger.Message("Calling function")
        Function(variable)
        
        run = False
        sleep(1)
except KeyboardInterrupt as exception:
    RPiLogger.Exception("Exception at main loop")
    RPiLogger.Warning(str(exception))
    RPiLogger.LeaveScope()
RPiLogger.LeaveScope()