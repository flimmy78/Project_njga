/******************************************************************************

                  ��Ȩ���� (C), 2001-2013, ������Ѷ�������޹�˾

 ******************************************************************************
  �� �� ��   : callback.h
  �� �� ��   : ����
  ��    ��   : yanghaifeng
  ��������   : 2013��4��1��
  ����޸�   :
  ��������   : callback.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��4��1��
    ��    ��   : yanghaifeng
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef __CALLBACK_H__
#define __CALLBACK_H__

//modified by chenyu 130522
#ifdef WIN32

#ifdef EV9000SIP_EXPORTS
#define EV9000SIP_API    __declspec(dllexport)
#else
#define EV9000SIP_API    __declspec(dllimport)
#endif

#else
#define EV9000SIP_API    extern
#endif //end WIN32

/*----------------------------------------------*
 * ����ͷ�ļ�                                   *
 *----------------------------------------------*/

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
    /* �ϲ�Ӧ�����õĻص����� */
    typedef struct _app_callback_t
    {
        /* ���������յ�ע����Ϣ�ص�����
             ����:proxy_id, ������ID
                  register_id, ע���id
                  from_ip, ��ԴIP
                  from_port, ��Դport
                  user_name ע���û���
                  reg_info_index,ע��������
                  expires,ʱ��
                  link_type,��������
           */
        int (*uas_register_received_cb)(char*, char*, char*, int, char*, int, int, int);

        /* �����û���յ��ͻ���ˢ��ע�ᳬʱ
             ����:proxy_id, ������ID
                  register_id, ע���id

                  from_ip, ��ԴIP
                  from_port, ��Դport
                  reg_info_index,ע��������
          */
        int (*uas_register_received_timeout_cb)(char*, char*, char*, int, int);

        /* �ͻ��˷���ע����Ϣ���յ�ע����Ӧ��Ϣ�ص�����
             ����:reg_info_index,ע��������
                  expires ��ʱʱ��
                  status_code,ע����Ӧ��Ϣ��
                  reasonphrase, ע����Ӧ�ľ���ԭ��
                  iTime, ���������ص�Уʱʱ��
           */
        int (*uac_register_response_received_cb)(int, int, int, char*, unsigned int, int);
        int uac_register_response_received_cb_user_data;

        /* �յ�������Ϣ�ص�����
             ����:        caller_id,�Ự��Դid
                          callee_id,�ỰĿ��id
                          call_id,�ỰΨһid
                          dialog_index,�Ự�������
                          body:Я����body��������
                          body_len:Я����body����
           */
        int (*invite_received_cb)(char*, char*, char*, int, char*, int, int);
        int invite_received_cb_user_data;

        /* �յ�������Ӧ��Ϣ�ص�����
             ����:        caller_id,�Ự��Դid
                          callee_id,�ỰĿ��id
                          call_id,�ỰΨһid
                          dialog_index,�Ự�������
                          status_code,������Ӧ��Ϣ��
                          reasonphrase, ������Ӧ�ľ���ԭ��
                          body:Я����body��������
                          body_len:Я����body����
        */
        int (*invite_response_received_cb)(char*, char*, char*, int, int, char*, char*, int, int);
        int invite_response_received_cb_user_data;

        /* �յ�Cancel ��Ϣ�ص�����
             ����:caller_id,�Ự��Դid
                          callee_id,�ỰĿ��id
                          call_id,�ỰΨһid
                          dialog_index,�Ự�������
           */
        int (*cancel_received_cb)(char*, char*, char*, int, int);
        int cancel_received_cb_user_data;

        /* �յ�ACK ��Ϣ�ص�����
             ����:caller_id,�Ự��Դid
                          callee_id,�ỰĿ��id
                          call_id,�ỰΨһid
                          dialog_index,�Ự�������
           */
        int (*ack_received_cb)(char*, char*, char*, int, int);
        int ack_received_cb_user_data;

        /* �յ����н�����Ϣ�ص�����
             ����:caller_id,�Ự��Դid
                          callee_id,�ỰĿ��id
                          call_id,�ỰΨһid
                          dialog_index,�Ự�������
        */
        int (*bye_received_cb)(char*, char*, char*, int, int);
        int bye_received_cb_user_data;

        /* �յ����н�����Ӧ��Ϣ�ص�����
             ����:caller_id,�Ự��Դid
                          callee_id,�ỰĿ��id
                          call_id,�ỰΨһid
                          dialog_index,�Ự�������
                          status_code,������Ӧ��Ϣ��
        */
        int (*bye_response_received_cb)(char*, char*, char*, int, int, int);
        int bye_response_received_cb_user_data;

        /* �յ�Message ��Ϣ�ص�����
             ����:        caller_id,���ͷ���device id
                          caller_ip ���ͷ���IP��ַ
                          caller_port ���ͷ��Ķ˿ں�
                          callee_id,���շ���device id
                          callee_ip ���շ���IP��ַ
                          callee_port ���շ��Ķ˿ں�
                          call_id:��message��ϢΨһ��call id
                          dialog_index,�Ự�������
                          msg:Я����msg��������
                          msg_len:Я����msg����
        */
        int (*message_received_cb)(char*, char*, int, char*, char*, int, char*, int, char*, int, int);
        int message_received_cb_user_data;

        /* �յ�Message ��Ӧ��Ϣ�ص�����
             ����:caller_id,���ͷ���device id
                          callee_id,���շ���device id
                          call_id:��message��ϢΨһ��call id
                          status_code:Message��Ӧ��Ϣ��
        */
        int (*message_response_received_cb)(char*, char*, char*, int, int);
        int message_response_received_cb_user_data;

        /* �յ�Subscribe ��Ϣ�ص�����
             ����:        caller_id,���ͷ���device id
                          caller_ip ���ͷ���IP��ַ
                          caller_port ���ͷ��Ķ˿ں�
                          callee_id,���շ���device id
                          callee_ip ���շ���IP��ַ
                          callee_port ���շ��Ķ˿ں�
                          call_id:��message��ϢΨһ��call id
                          event_type �¼�����
                          id_param �¼�����ID
                          subscribe_expires ��ʱʱ��
                          msg:Я����msg��������
                          msg_len:Я����msg����
        */
        int (*subscribe_received_cb)(char*, char*, int, char*, char*, int, char*, char*, char*, int, char*, int, int);
        int subscribe_received_cb_user_data;

        /* �յ�Subscribe ��Ӧ��Ϣ�ص�����
             ����:caller_id,���ͷ���device id
                          callee_id,���շ���device id
                          call_id:��message��ϢΨһ��call id
                          expires:���ĳ�ʱʱ��
                          status_code:Message��Ӧ��Ϣ��
        */
        int (*subscribe_response_received_cb)(char*, char*, char*, int, int, int);
        int subscribe_response_received_cb_user_data;

        /* �յ�Subscribe within dialog ��Ϣ�ص�����
             ����:        caller_id,�Ự��Դid
                          caller_ip ���ͷ���IP��ַ
                          caller_port ���ͷ��Ķ˿ں�
                          callee_id,�ỰĿ��id
                          call_id,�ỰΨһid
                          dialog_index,�Ự�������
                          subscribe_expires ��ʱʱ��
                          body:Я����body��������
                          body_len:Я����body����
            */
        int (*subscribe_within_dialog_received_cb)(char*, char*, int, char*, char*, int, int, char*, int);

        /* �յ�Subscribe ��Ӧ��Ϣ�ص�����
             ����:        caller_id,���ͷ���device id
                          callee_id,���շ���device id
                          call_id:��message��ϢΨһ��call id
                          dialog_index,�Ự�������
                          expires:���ĳ�ʱʱ��
                          status_code:Message��Ӧ��Ϣ��
            */
        int (*subscribe_within_dialog_response_received_cb)(char*, char*, char*, int, int, int);

        /* �յ� Notify ��Ϣ�ص�����
             ����:        caller_id,���ͷ���device id
                          caller_ip ���ͷ���IP��ַ
                          caller_port ���ͷ��Ķ˿ں�
                          callee_id,���շ���device id
                          callee_ip ���շ���IP��ַ
                          callee_port ���շ��Ķ˿ں�
                          call_id:��message��ϢΨһ��call id
                          msg:Я����msg��������
                          msg_len:Я����msg����
        */
        int (*notify_received_cb)(char*, char*, int, char*, char*, int, char*, char*, int, int);
        int notify_received_cb_user_data;

        /* �յ� Notify ��Ӧ��Ϣ�ص�����
             ����:caller_id,���ͷ���device id
                          callee_id,���շ���device id
                          call_id:��message��ϢΨһ��call id
                          status_code:Message��Ӧ��Ϣ��
        */
        int (*notify_response_received_cb)(char*, char*, char*, int, int);
        int notify_response_received_cb_user_data;

        /* �յ�Info ��Ϣ�ص�����
             ����:caller_id,���ͷ���device id
                          caller_ip ���ͷ���IP��ַ
                          caller_port ���ͷ��Ķ˿ں�
                          callee_id,���շ���device id
                          call_id:��Info��ϢΨһ��call id
                          dialog_index,�Ự�������
                          msg:Я����msg��������
                          msg_len:Я����msg����
        */
        int (*info_received_cb)(char*, char*, int, char*, char*, int, char*, int, int);
        int info_received_cb_user_data;

        /* �յ�Info ��Ӧ��Ϣ�ص�����
             ����:caller_id,���ͷ���device id
                          callee_id,���շ���device id
                          call_id:��Info��ϢΨһ��call id
                          status_code:Info��Ӧ��Ϣ��
        */
        int (*info_response_received_cb)(char*, char*, char*, int, int);
        int info_response_received_cb_user_data;

        /* UA �Ự��ʱ�ص�����
             ����:dialog_index,�Ự�������
           */
        int (*ua_session_expires_cb)(int);

        /* ���Դ�ӡ����
             ����:const char*
                          ...
            */
        void (*dbg_printf_cb)(int, const char*, const char*, int, const char*);

        /* SIP��Ϣ���Դ�ӡ����
             ����  : int type:
                            0,��ȷ��
                            1:���ʹ����
                            2:���ս��������
                            3:������Ϣ�����
                            4:���մ�����������
                            int iDirect:
                            0:���͵�
                            1:���յ�
                            char* ipaddr
                            int port
                            char* msg
            */
        void (*sip_message_trace_cb)(int, int, char*, int, char*);

    } app_callback_t;

    /*----------------------------------------------*
     * �궨��                                       *
     *----------------------------------------------*/
    extern void app_callback_free();
    extern int app_callback_init();
    EV9000SIP_API void app_set_ack_received_cb(int (*cb)(char*, char*, char*, int, int), int user_data);
    EV9000SIP_API void app_set_bye_received_cb(int (*cb)(char*, char*, char*, int, int), int user_data);
    EV9000SIP_API void app_set_bye_response_received_cb(int (*cb)(char*, char*, char*, int, int, int), int user_data);
    EV9000SIP_API void app_set_cancel_received_cb(int (*cb)(char*, char*, char*, int, int), int user_data);
    EV9000SIP_API void app_set_dbg_printf_cb(void (*cb)(int, const char*, const char*, int, const char*));
    EV9000SIP_API void app_set_info_received_cb(int (*cb)(char*, char*, int, char*, char*, int, char*, int, int), int user_data);
    EV9000SIP_API void app_set_info_response_received_cb(int (*cb)(char*, char*, char*, int, int), int user_data);
    EV9000SIP_API void app_set_invite_received_cb(int (*cb)(char*, char*, char*, int, char*, int, int), int user_data);
    EV9000SIP_API void app_set_invite_response_received_cb(int (*cb)(char*, char*, char*, int, int, char*, char*, int, int), int user_data);
    EV9000SIP_API void app_set_message_received_cb(int (*cb)(char*, char*, int, char*, char*, int, char*, int, char*, int, int), int user_data);
    EV9000SIP_API void app_set_message_response_received_cb(int (*cb)(char*, char*, char*, int, int), int user_data);
    EV9000SIP_API void app_set_notify_received_cb(int (*cb)(char*, char*, int, char*, char*, int, char*, char*, int, int), int user_data);
    EV9000SIP_API void app_set_notify_response_received_cb(int (*cb)(char*, char*, char*, int, int), int user_data);
    EV9000SIP_API void app_set_sip_message_trace_cb(void (*cb)(int, int, char*, int, char*));
    EV9000SIP_API void app_set_subscribe_received_cb(int (*cb)(char*, char*, int, char*, char*, int, char*, char*, char*, int, char*, int, int), int user_data);
    EV9000SIP_API void app_set_subscribe_response_received_cb(int (*cb)(char*, char*, char*, int, int, int), int user_data);
    EV9000SIP_API void app_set_subscribe_within_dialog_received_cb(int (*cb)(char*, char*, int, char*, char*, int, int, char*, int));
    EV9000SIP_API void app_set_subscribe_within_dialog_response_received_cb(int (*cb)(char*, char*, char*, int, int, int));
    EV9000SIP_API void app_set_uac_register_response_received_cb(int (*cb)(int, int, int, char*, unsigned int, int), int user_data);
    EV9000SIP_API void app_set_uas_register_received_cb(int (*cb)(char*, char*, char*, int, char*, int, int, int));
    EV9000SIP_API void app_set_uas_register_received_timeout_cb(int (*cb)(char*, char*, char*, int, int));
    EV9000SIP_API void app_set_ua_session_expires_cb(int (*cb)(int));
    extern void cs_cb_ict_2xx2(osip_message_t* sip);
    extern void cs_cb_ict_rcv1xx(int type, osip_transaction_t* tr , osip_message_t* sip);
    extern void cs_cb_ict_rcv2xx(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_ict_rcv3xx(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_ict_rcv456xx(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_ict_timeout(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_ist_ack_for2xx(osip_message_t* sip);
    extern void cs_cb_ist_snd1xx(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_ist_snd2xx(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_ist_snd3456xx(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_kill_ict_transaction_for_rcv(int type, osip_transaction_t* tr);
    extern void cs_cb_kill_ict_transaction_for_rcv_msg(int type, osip_transaction_t* tr);
    extern void cs_cb_kill_ict_transaction_for_rcv_register(int type, osip_transaction_t* tr);
    extern void cs_cb_kill_ict_transaction_for_send(int type, osip_transaction_t* tr);
    extern void cs_cb_kill_ict_transaction_for_send_msg(int type, osip_transaction_t* tr);
    extern void cs_cb_kill_ist_transaction_for_rcv(int type, osip_transaction_t* tr);
    extern void cs_cb_kill_ist_transaction_for_rcv_msg(int type, osip_transaction_t* tr);
    extern void cs_cb_kill_ist_transaction_for_rcv_register(int type, osip_transaction_t* tr);
    extern void cs_cb_kill_ist_transaction_for_send(int type, osip_transaction_t* tr);
    extern void cs_cb_kill_ist_transaction_for_send_msg(int type, osip_transaction_t* tr);
    extern void cs_cb_kill_nict_transaction_for_rcv(int type, osip_transaction_t* tr);
    extern void cs_cb_kill_nict_transaction_for_rcv_msg(int type, osip_transaction_t* tr);
    extern void cs_cb_kill_nict_transaction_for_rcv_register(int type, osip_transaction_t* tr);
    extern void cs_cb_kill_nict_transaction_for_send(int type, osip_transaction_t* tr);
    extern void cs_cb_kill_nict_transaction_for_send_msg(int type, osip_transaction_t* tr);
    extern void cs_cb_kill_nist_transaction_for_rcv(int type, osip_transaction_t* tr);
    extern void cs_cb_kill_nist_transaction_for_rcv_msg(int type, osip_transaction_t* tr);
    extern void cs_cb_kill_nist_transaction_for_rcv_register(int type, osip_transaction_t* tr);
    extern void cs_cb_kill_nist_transaction_for_send(int type, osip_transaction_t* tr);
    extern void cs_cb_kill_nist_transaction_for_send_msg(int type, osip_transaction_t* tr);
    extern void cs_cb_nict_rcv1xx(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_nict_rcv2xx(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_nict_rcv3xx(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_nict_rcv456xx(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_nict_timeout(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_nist_snd1xx(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_nist_snd2xx(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_nist_snd3456xx(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_rcvack(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_rcvack2(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_rcvbye(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_rcvcancel(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_rcvinfo(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_rcvinvite(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_rcvmessage(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_rcvnotify(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_rcvoptions(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_rcvrefer(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_rcvregister(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_rcvreq_retransmission(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_rcvresp_retransmission(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_rcvsubscribe(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_rcvunkrequest(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_rcvupdate(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_sndack(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_sndbye(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_sndcancel(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_sndinfo(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_sndinvite(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_sndoptions(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_sndregister(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_sndreq_retransmission(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_sndresp_retransmission(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_sndunkrequest(int type, osip_transaction_t* tr, osip_message_t* sip);
    extern void cs_cb_transport_error(int type, osip_transaction_t* tr, int error);
    extern int sip_callback_init(osip_t* cell);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __CALLBACK_H__ */