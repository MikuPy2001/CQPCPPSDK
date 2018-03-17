#pragma once

#include <Python.h>

#ifdef _DEBUG
#pragma comment(lib,"SDK_Debug.lib")
#else
#pragma comment(lib,"SDK_Release.lib")
#endif

#define CQAPPID "cn.mikupy2001.PYruntime"

bool py_init();

#include <memory>
std::shared_ptr<char*> U(const char* strGbk);
std::shared_ptr<char*> G(const char* strUtf8);
#define _U(CHAR) (*U(CHAR))
#define _G(CHAR) (*G(CHAR))

PyObject *getCQAPI();

extern bool 
py_isinit                       ,

py_t_Enable                     ,
py_t_Disable                    ,
py_t_Startup                    ,
py_t_Exit                       ,

py_t_DiscussMsg1                ,
py_t_DiscussMsg2                ,
py_t_DiscussMsg3                ,
py_t_DiscussMsg4                ,
py_t_Friend_Add1                ,
py_t_Friend_Add2                ,
py_t_Friend_Add3                ,
py_t_Friend_Add4                ,
py_t_GroupMsg1                  ,
py_t_GroupMsg2                  ,
py_t_GroupMsg3                  ,
py_t_GroupMsg4                  ,
py_t_GroupUpload1               ,
py_t_GroupUpload2               ,
py_t_GroupUpload3               ,
py_t_GroupUpload4               ,
py_t_PrivateMsg1                ,
py_t_PrivateMsg2                ,
py_t_PrivateMsg3                ,
py_t_PrivateMsg4                ,
py_t_Request_AddFriend1         ,
py_t_Request_AddFriend2         ,
py_t_Request_AddFriend3         ,
py_t_Request_AddFriend4         ,
py_t_Request_AddGroup1          ,
py_t_Request_AddGroup2          ,
py_t_Request_AddGroup3          ,
py_t_Request_AddGroup4          ,
py_t_System_GroupAdmin1         ,
py_t_System_GroupAdmin2         ,
py_t_System_GroupAdmin3         ,
py_t_System_GroupAdmin4         ,
py_t_System_GroupMemberDecrease1,
py_t_System_GroupMemberDecrease2,
py_t_System_GroupMemberDecrease3,
py_t_System_GroupMemberDecrease4,
py_t_System_GroupMemberIncrease1,
py_t_System_GroupMemberIncrease2,
py_t_System_GroupMemberIncrease3,
py_t_System_GroupMemberIncrease4;

extern PyObject
*py_RunTime                     ,
*py_printex,
*py_Enable                      ,
*py_Disable                     ,
*py_Exit                        ,
*py_DiscussMsg1                 ,
*py_DiscussMsg2                 ,
*py_DiscussMsg3                 ,
*py_DiscussMsg4                 ,
*py_Friend_Add1                 ,
*py_Friend_Add2                 ,
*py_Friend_Add3                 ,
*py_Friend_Add4                 ,
*py_GroupMsg1                   ,
*py_GroupMsg2                   ,
*py_GroupMsg3                   ,
*py_GroupMsg4                   ,
*py_GroupUpload1                ,
*py_GroupUpload2                ,
*py_GroupUpload3                ,
*py_GroupUpload4                ,
*py_PrivateMsg1                 ,
*py_PrivateMsg2                 ,
*py_PrivateMsg3                 ,
*py_PrivateMsg4                 ,
*py_Request_AddFriend1          ,
*py_Request_AddFriend2          ,
*py_Request_AddFriend3          ,
*py_Request_AddFriend4          ,
*py_Request_AddGroup1           ,
*py_Request_AddGroup2           ,
*py_Request_AddGroup3           ,
*py_Request_AddGroup4           ,
*py_Startup                     ,
*py_System_GroupAdmin1          ,
*py_System_GroupAdmin2          ,
*py_System_GroupAdmin3          ,
*py_System_GroupAdmin4          ,
*py_System_GroupMemberDecrease1 ,
*py_System_GroupMemberDecrease2 ,
*py_System_GroupMemberDecrease3 ,
*py_System_GroupMemberDecrease4 ,
*py_System_GroupMemberIncrease1 ,
*py_System_GroupMemberIncrease2 ,
*py_System_GroupMemberIncrease3 ,
*py_System_GroupMemberIncrease4;
