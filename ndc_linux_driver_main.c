#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/usb.h>
#include "ndc_defs.h"


MODULE_AUTHOR("Itay Avraham <itayavr@nvidia.com>");
MODULE_DESCRIPTION("Driver for the NDC adapter (Nvidia Debug Controller)");
MODULE_LICENSE("GPL v2");


static const struct usb_device_id ndc_table[] = {
	{ USB_DEVICE(NDC_VENDOR_ID, NDC_PRODUCT_ID) },
    { }
};
MODULE_DEVICE_TABLE(usb, ndc_table);


static struct usb_driver ndc_driver_callback = {
	.name = NDC_DRIVER_NAME,
	.id_table = ndc_table
};




static int __init ndc_driver_init(void)
{
    int error_code;

    // Register this driver with the USB subsystem.
    error_code = usb_register(&ndc_driver_callback);
    if (error_code < 0) {
            ndc_error("usb_register failed to register the NDC driver, error number %d\n", error_code);
            return -1;
    }

    return 0;
}
module_init(ndc_driver_init);




static void __exit ndc_driver_exit(void)
{
    // Deregister this driver with the USB subsystem.
    usb_deregister(&ndc_driver_callback);
}
module_exit(ndc_driver_exit);
