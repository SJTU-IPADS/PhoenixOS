log_conf = configuration_data()

log_conf.set('pos_print_error', enable_print_error)
log_conf.set('pos_print_warn', enable_print_warn)
log_conf.set('pos_print_log', enable_print_log)
log_conf.set('pos_print_debug', enable_print_debug)
log_conf.set('pos_print_with_color', enable_print_with_color)
configure_file(input : 'log.h.in', output : 'log.h', configuration : log_conf)
