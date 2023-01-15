#ifndef NDC_DEFS_H
#define NDC_DEFS_H


#include <linux/kernel.h>
#include <linux/fs.h>


#define NDC_DRIVER_NAME         "ndc_driver"
#define NDC_VENDOR_ID           0x0483
#define NDC_PRODUCT_ID          0x5740

#define ndc_error(format, arg...) \
    pr_err("%s function name:%s, line:%d | " format, NDC_DRIVER_NAME, __func__, __LINE__, ## arg)

#define ndc_debug(format, arg...) \
    pr_debug("%s function name:%s, line: %d | " format, NDC_DRIVER_NAME, __func__, __LINE__, ## arg)


#endif // NDC_DEFS_H
