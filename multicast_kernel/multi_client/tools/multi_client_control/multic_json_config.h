#ifndef __MULTI_JSON_CONFIG__
#define __MULTI_JSON_CONFIG__

#include <arpa/inet.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <assert.h>
#include <linux/netlink.h>

#define MULTI_CLIENT_CONFIG_FILE "/usr/local/etc/multi_client_running_config"
#define MULTI_GROUP_ARRAY "multi_server_info_array"
#define MULTI_GROUP_IP "group_ip"
#define MULTI_SERVER_IP "server_ip"
#define MULTI_CLIENT_PORT "client_port"

int multi_grp_add_to_config(struct tmcc_nl_service_st *grp);
int multi_grp_del_from_config(struct tmcc_nl_service_st *grp);
int multi_grp_config_init(char * filepath);

#define VALUE_IS_NULL_PRINT_AND_RETURN(value, string, retnum) \
{ \
    if(value == NULL){ \
        printf("%s\n", string); \
        return -retnum;  \
    } \
}


#define VALUE_IS_NEGATIVE_PRINT_AND_RETURN(value, string, retnum) \
{ \
    if(value < 0){ \
        printf("%s\n", string); \
        return -retnum;  \
    } \
}


#define VALUE_IS_NULL_RETURN(value, retnum) \
    if(value == NULL) return -retnum

#define VALUE_IS_NOTNULL_RETURN(value, retnum) \
    if(value != NULL) return -retnum

#define VALUE_IS_NULL_GOTO(value, FAIL) \
    if(value == NULL) goto FAIL

#define VALUE_IS_NEGATIVE_GOTO(value, FAIL) \
    if(value < 0) goto FAIL

#define VALUE_IS_NULL_PRINT_AND_GOTO_FAIL(val, string, out) \
{   \
    if(val == NULL){ \
        ret = -out;   \
        printf("%s\n", string); \
        goto FAIL; \
    }  \
}


int nf_file_lock(char * filename);
int nf_file_unlock(int fd);
int n_json_del_element_from_array_by_idx( struct json_object * obj, int idx );
int nf_json_config_get_root(char *configfile, const char *key, 
                                json_object **root, json_object **root_config);
int nf_json_config_init_object(json_object *parent, const char *childkey,
                                json_object **child);
int nf_json_config_init_array(json_object *parent, const char *childkey, 
                                json_object **child);
int nf_json_config_init_int(json_object *parent, const char *childkey, 
                                json_object **child, int value);
int nf_json_config_init_string(json_object *parent, const char *childkey, 
                                json_object **child, const char *str);
int nf_json_config_root_init(json_object **root);

#endif
