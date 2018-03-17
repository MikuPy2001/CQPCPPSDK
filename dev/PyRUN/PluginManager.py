import sys,traceback,os


def PrivateMsg1(subType, msgId, fromQQ, msg, font):
    try:
        CQ.addLog(0,"私聊事件",fromQQ+"发来消息:"+msg)
    except Exception as e:
        getex()
    return 1;
def getex():
    exc_type, exc_value, exc_tb = sys.exc_info()
    tb=traceback.extract_tb(exc_tb)
    ex='exception:'+str(exc_type)+':'+str(exc_value)+os.linesep
    for filename, linenum, funcname, source in tb[::-1]:
        ex+=str(filename)+" <line " +str(linenum)+"> " +str(funcname)+os.linesep
        ex+="    "+str(source)+os.linesep
    print(ex)
    return ex;
PrivateMsg1(1,2,3,"",4)
def fileput(ex):
    f=open("out.txt",mode='a',newline="\n")
    f.write(ex+os.linesep)
    f.close
