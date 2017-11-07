#ifndef __COMMON_THREAD_PROC_H__
#define __COMMON_THREAD_PROC_H__


/*----------------------------------------------*
 * ����ͷ�ļ�                                   *
 *----------------------------------------------*/
#include <sys/types.h>
#ifdef WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#endif

#include "libsip.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

    /*----------------------------------------------*
     * �ⲿ����˵��                                 *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * �ⲿ����ԭ��˵��                             *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * �ڲ�����ԭ��˵��                             *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * ȫ�ֱ���                                     *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * ģ�鼶����                                   *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * ��������                                     *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * �궨��                                       *
     *----------------------------------------------*/
    /* �����߳̽ṹ�� */
    typedef struct _thread_proc_t
    {
        proc_thread_type_t eThreadType;     /* �߳����� */
        osip_thread_t* thread;              /* �߳̾�� */
        int th_exit;                        /* ������ʶ */
        time_t  run_time;                   /* ����ʱ�� */
        DBOper* pDbOper;                    /* ���ݿ����ӱ�ʶ */
        DBOper* pLogDbOper;                 /* ��־���ݿ����ӱ�ʶ */
        int iLogDBOperConnectStatus;        /* ��־���ݿ�����״̬ */
    } thread_proc_t;

    /* �̴߳������� */
    typedef struct _thread_proc_list_t
    {
        osip_list_t* pThreadProcList;
#ifdef MULTI_THR
        osip_mutex_t* lock;
#endif
    } thread_proc_list_t;

    /* ������ҵ���̶߳��� */
    typedef std::deque <thread_proc_t*> needtoproc_threadproc_queue;

    extern void* common_db_refresh_thread_execute(void* p);
    extern void* config_mgn_proc_thread_execute(void* p);
    extern int debug_thread_proc_list_lock(const char* file, int line, const char* func);
    extern int debug_thread_proc_list_unlock(const char* file, int line, const char* func);
    extern int get_thread_name_by_type(proc_thread_type_t eThreadType, char* strThreadName, int* pMsgSize);
    extern void* log2db_proc_thread_execute(void* p);
    extern int log2db_proc_thread_start();
    extern void  log2db_proc_thread_stop();
    extern void* log2file_proc_thread_execute(void* p);
    extern int log2file_proc_thread_start();
    extern void  log2file_proc_thread_stop();
    extern void* platform_mgn_proc_thread_execute(void* p);
    extern void scan_thread_proc_list();
    extern void show_system_proc_thread(int sock);
    extern void* telnet_client_monitor_thread_execute(void* p);
    extern void* thread_monitor_proc_thread_execute(void* p);
    extern int thread_monitor_proc_thread_start();
    extern void  thread_monitor_proc_thread_stop();
    extern int thread_proc_add(thread_proc_t* pThreadProc);
    extern thread_proc_t* thread_proc_find(proc_thread_type_t eThreadType);
    extern void thread_proc_list_free();
    extern int thread_proc_list_init();
    extern int thread_proc_list_lock();
    extern int thread_proc_list_unlock();
    extern int thread_proc_remove(proc_thread_type_t eThreadType);
    extern int thread_proc_thread_start(proc_thread_type_t eThreadType);
    extern int thread_proc_thread_start_all();
    extern void thread_proc_thread_stop(proc_thread_type_t eThreadType);
    extern void thread_proc_thread_stop_all();
    extern void thread_proc_t_free(thread_proc_t* run);
    extern int thread_proc_t_init(thread_proc_t** run);
    extern void* zrv_compress_task_monitor_thread_execute(void* p);
    extern void* zrv_device_mgn_proc_thread_execute(void* p);
    extern void* zrv_device_tcp_connect_proc_thread_execute(void* p);
    extern void* zrv_task_result_msg_proc_thread_execute(void* p);

#ifdef ENABLE_DEBUG_LOCK
#define THREAD_PROC_SMUTEX_LOCK() debug_thread_proc_list_lock(__FILE__, __LINE__, __func__)
#define THREAD_PROC_SMUTEX_UNLOCK() debug_thread_proc_list_unlock(__FILE__, __LINE__, __func__)
#else
#define THREAD_PROC_SMUTEX_LOCK() thread_proc_list_lock()
#define THREAD_PROC_SMUTEX_UNLOCK() thread_proc_list_unlock()
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __UDP_TL_H__ */