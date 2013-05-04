#include "fitz-internal.h"
#include "mupdf-internal.h"

// EBD: >>>
//#ifndef NOCJK
// EBD: <<<
#include "../generated/cmap_cns.h"
#include "../generated/cmap_gb.h"
#include "../generated/cmap_japan.h"
#include "../generated/cmap_korea.h"
// EBD: >>>
//#endif
// EBD: <<<

static const struct { char *name; pdf_cmap *cmap; } cmap_table[] =
{
// EBD: >>>
//#ifndef NOCJK
// EBD: <<<
	{"78-EUC-H",&cmap_78_EUC_H},
	{"78-EUC-V",&cmap_78_EUC_V},
	{"78-H",&cmap_78_H},
	{"78-RKSJ-H",&cmap_78_RKSJ_H},
	{"78-RKSJ-V",&cmap_78_RKSJ_V},
	{"78-V",&cmap_78_V},
	{"78ms-RKSJ-H",&cmap_78ms_RKSJ_H},
	{"78ms-RKSJ-V",&cmap_78ms_RKSJ_V},
	{"83pv-RKSJ-H",&cmap_83pv_RKSJ_H},
	{"90ms-RKSJ-H",&cmap_90ms_RKSJ_H},
	{"90ms-RKSJ-V",&cmap_90ms_RKSJ_V},
	{"90msp-RKSJ-H",&cmap_90msp_RKSJ_H},
	{"90msp-RKSJ-V",&cmap_90msp_RKSJ_V},
	{"90pv-RKSJ-H",&cmap_90pv_RKSJ_H},
	{"90pv-RKSJ-V",&cmap_90pv_RKSJ_V},
	{"Add-H",&cmap_Add_H},
	{"Add-RKSJ-H",&cmap_Add_RKSJ_H},
	{"Add-RKSJ-V",&cmap_Add_RKSJ_V},
	{"Add-V",&cmap_Add_V},
	{"Adobe-CNS1-0",&cmap_Adobe_CNS1_0},
	{"Adobe-CNS1-1",&cmap_Adobe_CNS1_1},
	{"Adobe-CNS1-2",&cmap_Adobe_CNS1_2},
	{"Adobe-CNS1-3",&cmap_Adobe_CNS1_3},
	{"Adobe-CNS1-4",&cmap_Adobe_CNS1_4},
	{"Adobe-CNS1-5",&cmap_Adobe_CNS1_5},
	{"Adobe-CNS1-6",&cmap_Adobe_CNS1_6},
	{"Adobe-CNS1-UCS2",&cmap_Adobe_CNS1_UCS2},
	{"Adobe-GB1-0",&cmap_Adobe_GB1_0},
	{"Adobe-GB1-1",&cmap_Adobe_GB1_1},
	{"Adobe-GB1-2",&cmap_Adobe_GB1_2},
	{"Adobe-GB1-3",&cmap_Adobe_GB1_3},
	{"Adobe-GB1-4",&cmap_Adobe_GB1_4},
	{"Adobe-GB1-5",&cmap_Adobe_GB1_5},
	{"Adobe-GB1-UCS2",&cmap_Adobe_GB1_UCS2},
	{"Adobe-Japan1-0",&cmap_Adobe_Japan1_0},
	{"Adobe-Japan1-1",&cmap_Adobe_Japan1_1},
	{"Adobe-Japan1-2",&cmap_Adobe_Japan1_2},
	{"Adobe-Japan1-3",&cmap_Adobe_Japan1_3},
	{"Adobe-Japan1-4",&cmap_Adobe_Japan1_4},
	{"Adobe-Japan1-5",&cmap_Adobe_Japan1_5},
	{"Adobe-Japan1-6",&cmap_Adobe_Japan1_6},
	{"Adobe-Japan1-UCS2",&cmap_Adobe_Japan1_UCS2},
	{"Adobe-Japan2-0",&cmap_Adobe_Japan2_0},
	{"Adobe-Korea1-0",&cmap_Adobe_Korea1_0},
	{"Adobe-Korea1-1",&cmap_Adobe_Korea1_1},
	{"Adobe-Korea1-2",&cmap_Adobe_Korea1_2},
	{"Adobe-Korea1-UCS2",&cmap_Adobe_Korea1_UCS2},
	{"B5-H",&cmap_B5_H},
	{"B5-V",&cmap_B5_V},
	{"B5pc-H",&cmap_B5pc_H},
	{"B5pc-V",&cmap_B5pc_V},
	{"CNS-EUC-H",&cmap_CNS_EUC_H},
	{"CNS-EUC-V",&cmap_CNS_EUC_V},
	{"CNS1-H",&cmap_CNS1_H},
	{"CNS1-V",&cmap_CNS1_V},
	{"CNS2-H",&cmap_CNS2_H},
	{"CNS2-V",&cmap_CNS2_V},
	{"ETHK-B5-H",&cmap_ETHK_B5_H},
	{"ETHK-B5-V",&cmap_ETHK_B5_V},
	{"ETen-B5-H",&cmap_ETen_B5_H},
	{"ETen-B5-V",&cmap_ETen_B5_V},
	{"ETenms-B5-H",&cmap_ETenms_B5_H},
	{"ETenms-B5-V",&cmap_ETenms_B5_V},
	{"EUC-H",&cmap_EUC_H},
	{"EUC-V",&cmap_EUC_V},
	{"Ext-H",&cmap_Ext_H},
	{"Ext-RKSJ-H",&cmap_Ext_RKSJ_H},
	{"Ext-RKSJ-V",&cmap_Ext_RKSJ_V},
	{"Ext-V",&cmap_Ext_V},
	{"GB-EUC-H",&cmap_GB_EUC_H},
	{"GB-EUC-V",&cmap_GB_EUC_V},
	{"GB-H",&cmap_GB_H},
	{"GB-V",&cmap_GB_V},
	{"GBK-EUC-H",&cmap_GBK_EUC_H},
	{"GBK-EUC-V",&cmap_GBK_EUC_V},
	{"GBK2K-H",&cmap_GBK2K_H},
	{"GBK2K-V",&cmap_GBK2K_V},
	{"GBKp-EUC-H",&cmap_GBKp_EUC_H},
	{"GBKp-EUC-V",&cmap_GBKp_EUC_V},
	{"GBT-EUC-H",&cmap_GBT_EUC_H},
	{"GBT-EUC-V",&cmap_GBT_EUC_V},
	{"GBT-H",&cmap_GBT_H},
	{"GBT-V",&cmap_GBT_V},
	{"GBTpc-EUC-H",&cmap_GBTpc_EUC_H},
	{"GBTpc-EUC-V",&cmap_GBTpc_EUC_V},
	{"GBpc-EUC-H",&cmap_GBpc_EUC_H},
	{"GBpc-EUC-V",&cmap_GBpc_EUC_V},
	{"H",&cmap_H},
	{"HKdla-B5-H",&cmap_HKdla_B5_H},
	{"HKdla-B5-V",&cmap_HKdla_B5_V},
	{"HKdlb-B5-H",&cmap_HKdlb_B5_H},
	{"HKdlb-B5-V",&cmap_HKdlb_B5_V},
	{"HKgccs-B5-H",&cmap_HKgccs_B5_H},
	{"HKgccs-B5-V",&cmap_HKgccs_B5_V},
	{"HKm314-B5-H",&cmap_HKm314_B5_H},
	{"HKm314-B5-V",&cmap_HKm314_B5_V},
	{"HKm471-B5-H",&cmap_HKm471_B5_H},
	{"HKm471-B5-V",&cmap_HKm471_B5_V},
	{"HKscs-B5-H",&cmap_HKscs_B5_H},
	{"HKscs-B5-V",&cmap_HKscs_B5_V},
	{"Hankaku",&cmap_Hankaku},
	{"Hiragana",&cmap_Hiragana},
	{"Hojo-EUC-H",&cmap_Hojo_EUC_H},
	{"Hojo-EUC-V",&cmap_Hojo_EUC_V},
	{"Hojo-H",&cmap_Hojo_H},
	{"Hojo-V",&cmap_Hojo_V},
	{"KSC-EUC-H",&cmap_KSC_EUC_H},
	{"KSC-EUC-V",&cmap_KSC_EUC_V},
	{"KSC-H",&cmap_KSC_H},
	{"KSC-Johab-H",&cmap_KSC_Johab_H},
	{"KSC-Johab-V",&cmap_KSC_Johab_V},
	{"KSC-V",&cmap_KSC_V},
	{"KSCms-UHC-H",&cmap_KSCms_UHC_H},
	{"KSCms-UHC-HW-H",&cmap_KSCms_UHC_HW_H},
	{"KSCms-UHC-HW-V",&cmap_KSCms_UHC_HW_V},
	{"KSCms-UHC-V",&cmap_KSCms_UHC_V},
	{"KSCpc-EUC-H",&cmap_KSCpc_EUC_H},
	{"KSCpc-EUC-V",&cmap_KSCpc_EUC_V},
	{"Katakana",&cmap_Katakana},
	{"NWP-H",&cmap_NWP_H},
	{"NWP-V",&cmap_NWP_V},
	{"RKSJ-H",&cmap_RKSJ_H},
	{"RKSJ-V",&cmap_RKSJ_V},
	{"Roman",&cmap_Roman},
	{"UniCNS-UCS2-H",&cmap_UniCNS_UCS2_H},
	{"UniCNS-UCS2-V",&cmap_UniCNS_UCS2_V},
	{"UniCNS-UTF16-H",&cmap_UniCNS_UTF16_H},
	{"UniCNS-UTF16-V",&cmap_UniCNS_UTF16_V},
	{"UniGB-UCS2-H",&cmap_UniGB_UCS2_H},
	{"UniGB-UCS2-V",&cmap_UniGB_UCS2_V},
	{"UniGB-UTF16-H",&cmap_UniGB_UTF16_H},
	{"UniGB-UTF16-V",&cmap_UniGB_UTF16_V},
	{"UniHojo-UCS2-H",&cmap_UniHojo_UCS2_H},
	{"UniHojo-UCS2-V",&cmap_UniHojo_UCS2_V},
	{"UniHojo-UTF16-H",&cmap_UniHojo_UTF16_H},
	{"UniHojo-UTF16-V",&cmap_UniHojo_UTF16_V},
	{"UniJIS-UCS2-H",&cmap_UniJIS_UCS2_H},
	{"UniJIS-UCS2-HW-H",&cmap_UniJIS_UCS2_HW_H},
	{"UniJIS-UCS2-HW-V",&cmap_UniJIS_UCS2_HW_V},
	{"UniJIS-UCS2-V",&cmap_UniJIS_UCS2_V},
	{"UniJIS-UTF16-H",&cmap_UniJIS_UTF16_H},
	{"UniJIS-UTF16-V",&cmap_UniJIS_UTF16_V},
	{"UniJISPro-UCS2-HW-V",&cmap_UniJISPro_UCS2_HW_V},
	{"UniJISPro-UCS2-V",&cmap_UniJISPro_UCS2_V},
	{"UniKS-UCS2-H",&cmap_UniKS_UCS2_H},
	{"UniKS-UCS2-V",&cmap_UniKS_UCS2_V},
	{"UniKS-UTF16-H",&cmap_UniKS_UTF16_H},
	{"UniKS-UTF16-V",&cmap_UniKS_UTF16_V},
	{"V",&cmap_V},
	{"WP-Symbol",&cmap_WP_Symbol},
// EBD: >>>
//#endif
// EBD: <<<
};

pdf_cmap *
pdf_load_builtin_cmap(fz_context *ctx, char *cmap_name)
{
	int l = 0;
	int r = nelem(cmap_table) - 1;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		int c = strcmp(cmap_name, cmap_table[m].name);
		if (c < 0)
			r = m - 1;
		else if (c > 0)
			l = m + 1;
		else
			return cmap_table[m].cmap;
	}
	return NULL;
}
