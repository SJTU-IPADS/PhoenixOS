switches_conf = configuration_data()
log_conf = configuration_data()
config_conf = configuration_data()

switches_conf.set('pos_enable_debug_check', enable_runtime_debug_check)
switches_conf.set('pos_enable_hijack_api_check', enable_hijack_api_check)
switches_conf.set('pos_enable_checkpoint', enable_checkpoint)
configure_file(input : 'switches.h.in', output : 'switches.h', configuration : switches_conf)

log_conf.set('pos_print_error', enable_print_error)
log_conf.set('pos_print_warn', enable_print_warn)
log_conf.set('pos_print_log', enable_print_log)
log_conf.set('pos_print_debug', enable_print_debug)
log_conf.set('pos_print_with_color', enable_print_with_color)
configure_file(input : 'log.h.in', output : 'log.h', configuration : log_conf)

config_conf.set('pos_tsc_freq', tsc_reg_freq)
configure_file(input : 'config.h.in', output : 'config.h', configuration : config_conf)
