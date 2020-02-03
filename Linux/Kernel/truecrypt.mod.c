#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
};

static const struct modversion_info ____versions[]
__attribute_used__
__attribute__((section("__versions"))) = {
	{ 0x6b61daec, "struct_module" },
	{ 0xd80948cf, "kmem_cache_destroy" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0x8b398bc9, "bio_alloc" },
	{ 0x89b301d4, "param_get_int" },
	{ 0x30d2aa71, "dm_get_device" },
	{ 0xfa6e72dd, "malloc_sizes" },
	{ 0x1b0239f4, "dm_table_get_mode" },
	{ 0xe5077a8f, "mempool_destroy" },
	{ 0xed3180d6, "queue_work" },
	{ 0x547ee5a7, "dm_register_target" },
	{ 0x98bd6f46, "param_set_int" },
	{ 0x1d26aa98, "sprintf" },
	{ 0xda4008e6, "cond_resched" },
	{ 0x6f7f9fa1, "kunmap_atomic" },
	{ 0x330bbfa, "__create_workqueue" },
	{ 0x183fa88b, "mempool_alloc_slab" },
	{ 0xc4ccd918, "kmap_atomic" },
	{ 0x164152d5, "__alloc_pages" },
	{ 0x1b7d4074, "printk" },
	{ 0x859204af, "sscanf" },
	{ 0x5152e605, "memcmp" },
	{ 0x5d778c29, "dm_unregister_target" },
	{ 0xace6a8, "destroy_workqueue" },
	{ 0x27791ea7, "generic_make_request" },
	{ 0x8a99a016, "mempool_free_slab" },
	{ 0x1d17e4bd, "blk_congestion_wait" },
	{ 0xb10466a1, "contig_page_data" },
	{ 0xe2bec459, "bio_endio" },
	{ 0x23954266, "bio_put" },
	{ 0xbae4edc8, "kmem_cache_alloc" },
	{ 0x96aed08, "__free_pages" },
	{ 0xcfaf79ba, "mempool_alloc" },
	{ 0xbe8a1485, "mempool_create" },
	{ 0x37a9798f, "mempool_free" },
	{ 0x98ac8350, "kmem_cache_create" },
	{ 0xd5e8dba8, "init_timer" },
	{ 0x37a0cba, "kfree" },
	{ 0x9fc3282d, "dm_put_device" },
	{ 0x25da070, "snprintf" },
};

static const char __module_depends[]
__attribute_used__
__attribute__((section(".modinfo"))) =
"depends=dm-mod";


MODULE_INFO(srcversion, "37BE0E2FDE167BC5F918687");
