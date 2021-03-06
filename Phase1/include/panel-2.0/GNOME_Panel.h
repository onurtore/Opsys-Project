/*
 * This file was generated by orbit-idl-2 - DO NOT EDIT!
 */

#ifndef GNOME_Panel_H
#define GNOME_Panel_H 1
#include <glib.h>
#define ORBIT_IDL_SERIAL 19
#include <orbit/orbit-types.h>

#ifdef __cplusplus
extern "C"
{
#endif				/* __cplusplus */

/** typedefs **/
#include <bonobo-activation/Bonobo_Unknown.h>
#if !defined(_GNOME_Vertigo_PanelOrient_defined)
#define _GNOME_Vertigo_PanelOrient_defined 1
   typedef CORBA_unsigned_short GNOME_Vertigo_PanelOrient;
#define GNOME_Vertigo_PanelOrient_marshal(x,y,z) CORBA_unsigned_short_marshal((x),(y),(z))
#define GNOME_Vertigo_PanelOrient_demarshal(x,y,z,i) CORBA_unsigned_short_demarshal((x),(y),(z),(i))
#if !defined(TC_IMPL_TC_GNOME_Vertigo_PanelOrient_0)
#define TC_IMPL_TC_GNOME_Vertigo_PanelOrient_0 'G'
#define TC_IMPL_TC_GNOME_Vertigo_PanelOrient_1 'N'
#define TC_IMPL_TC_GNOME_Vertigo_PanelOrient_2 'O'
#define TC_IMPL_TC_GNOME_Vertigo_PanelOrient_3 'M'
#define TC_IMPL_TC_GNOME_Vertigo_PanelOrient_4 'E'
#define TC_IMPL_TC_GNOME_Vertigo_PanelOrient_5 '_'
#define TC_IMPL_TC_GNOME_Vertigo_PanelOrient_6 'P'
#define TC_IMPL_TC_GNOME_Vertigo_PanelOrient_7 'a'
#define TC_IMPL_TC_GNOME_Vertigo_PanelOrient_8 'n'
#define TC_IMPL_TC_GNOME_Vertigo_PanelOrient_9 'e'
#define TC_IMPL_TC_GNOME_Vertigo_PanelOrient_10 'l'
#ifdef ORBIT_IDL_C_IMODULE_GNOME_Panel
   static
#else
   extern
#endif
   const struct CORBA_TypeCode_struct TC_GNOME_Vertigo_PanelOrient_struct;
#define TC_GNOME_Vertigo_PanelOrient ((CORBA_TypeCode)&TC_GNOME_Vertigo_PanelOrient_struct)
#endif
#define GNOME_Vertigo_PanelOrient__alloc() ((GNOME_Vertigo_PanelOrient *)ORBit_small_alloc (TC_CORBA_unsigned_short))
#define GNOME_Vertigo_PanelOrient__freekids(m,d) ORBit_small_freekids (TC_CORBA_unsigned_short,(m),(d))
#endif
#ifndef GNOME_Vertigo_PANEL_ORIENT_UP
#define GNOME_Vertigo_PANEL_ORIENT_UP 0U
#endif				/* !GNOME_Vertigo_PANEL_ORIENT_UP */

#ifndef GNOME_Vertigo_PANEL_ORIENT_DOWN
#define GNOME_Vertigo_PANEL_ORIENT_DOWN 1U
#endif				/* !GNOME_Vertigo_PANEL_ORIENT_DOWN */

#ifndef GNOME_Vertigo_PANEL_ORIENT_LEFT
#define GNOME_Vertigo_PANEL_ORIENT_LEFT 2U
#endif				/* !GNOME_Vertigo_PANEL_ORIENT_LEFT */

#ifndef GNOME_Vertigo_PANEL_ORIENT_RIGHT
#define GNOME_Vertigo_PANEL_ORIENT_RIGHT 3U
#endif				/* !GNOME_Vertigo_PANEL_ORIENT_RIGHT */

#if !defined(_GNOME_Vertigo_PanelSize_defined)
#define _GNOME_Vertigo_PanelSize_defined 1
   typedef CORBA_unsigned_short GNOME_Vertigo_PanelSize;
#define GNOME_Vertigo_PanelSize_marshal(x,y,z) CORBA_unsigned_short_marshal((x),(y),(z))
#define GNOME_Vertigo_PanelSize_demarshal(x,y,z,i) CORBA_unsigned_short_demarshal((x),(y),(z),(i))
#if !defined(TC_IMPL_TC_GNOME_Vertigo_PanelSize_0)
#define TC_IMPL_TC_GNOME_Vertigo_PanelSize_0 'G'
#define TC_IMPL_TC_GNOME_Vertigo_PanelSize_1 'N'
#define TC_IMPL_TC_GNOME_Vertigo_PanelSize_2 'O'
#define TC_IMPL_TC_GNOME_Vertigo_PanelSize_3 'M'
#define TC_IMPL_TC_GNOME_Vertigo_PanelSize_4 'E'
#define TC_IMPL_TC_GNOME_Vertigo_PanelSize_5 '_'
#define TC_IMPL_TC_GNOME_Vertigo_PanelSize_6 'P'
#define TC_IMPL_TC_GNOME_Vertigo_PanelSize_7 'a'
#define TC_IMPL_TC_GNOME_Vertigo_PanelSize_8 'n'
#define TC_IMPL_TC_GNOME_Vertigo_PanelSize_9 'e'
#define TC_IMPL_TC_GNOME_Vertigo_PanelSize_10 'l'
#ifdef ORBIT_IDL_C_IMODULE_GNOME_Panel
   static
#else
   extern
#endif
   const struct CORBA_TypeCode_struct TC_GNOME_Vertigo_PanelSize_struct;
#define TC_GNOME_Vertigo_PanelSize ((CORBA_TypeCode)&TC_GNOME_Vertigo_PanelSize_struct)
#endif
#define GNOME_Vertigo_PanelSize__alloc() ((GNOME_Vertigo_PanelSize *)ORBit_small_alloc (TC_CORBA_unsigned_short))
#define GNOME_Vertigo_PanelSize__freekids(m,d) ORBit_small_freekids (TC_CORBA_unsigned_short,(m),(d))
#endif
#ifndef GNOME_Vertigo_PANEL_XX_SMALL
#define GNOME_Vertigo_PANEL_XX_SMALL 12U
#endif				/* !GNOME_Vertigo_PANEL_XX_SMALL */

#ifndef GNOME_Vertigo_PANEL_X_SMALL
#define GNOME_Vertigo_PANEL_X_SMALL 24U
#endif				/* !GNOME_Vertigo_PANEL_X_SMALL */

#ifndef GNOME_Vertigo_PANEL_SMALL
#define GNOME_Vertigo_PANEL_SMALL 36U
#endif				/* !GNOME_Vertigo_PANEL_SMALL */

#ifndef GNOME_Vertigo_PANEL_MEDIUM
#define GNOME_Vertigo_PANEL_MEDIUM 48U
#endif				/* !GNOME_Vertigo_PANEL_MEDIUM */

#ifndef GNOME_Vertigo_PANEL_LARGE
#define GNOME_Vertigo_PANEL_LARGE 64U
#endif				/* !GNOME_Vertigo_PANEL_LARGE */

#ifndef GNOME_Vertigo_PANEL_X_LARGE
#define GNOME_Vertigo_PANEL_X_LARGE 80U
#endif				/* !GNOME_Vertigo_PANEL_X_LARGE */

#ifndef GNOME_Vertigo_PANEL_XX_LARGE
#define GNOME_Vertigo_PANEL_XX_LARGE 128U
#endif				/* !GNOME_Vertigo_PANEL_XX_LARGE */

#if !defined(ORBIT_DECL_CORBA_sequence_CORBA_long)
#define ORBIT_DECL_CORBA_sequence_CORBA_long 1
#define ORBIT_IMPL_CORBA_sequence_CORBA_long_0 'G'
#define ORBIT_IMPL_CORBA_sequence_CORBA_long_1 'N'
#define ORBIT_IMPL_CORBA_sequence_CORBA_long_2 'O'
#define ORBIT_IMPL_CORBA_sequence_CORBA_long_3 'M'
#define ORBIT_IMPL_CORBA_sequence_CORBA_long_4 'E'
#define ORBIT_IMPL_CORBA_sequence_CORBA_long_5 '_'
#define ORBIT_IMPL_CORBA_sequence_CORBA_long_6 'P'
#define ORBIT_IMPL_CORBA_sequence_CORBA_long_7 'a'
#define ORBIT_IMPL_CORBA_sequence_CORBA_long_8 'n'
#define ORBIT_IMPL_CORBA_sequence_CORBA_long_9 'e'
#define ORBIT_IMPL_CORBA_sequence_CORBA_long_10 'l'
#if !defined(_CORBA_sequence_CORBA_long_defined)
#define _CORBA_sequence_CORBA_long_defined 1
   typedef struct
   {
      CORBA_unsigned_long _maximum,
       _length;
      CORBA_long *_buffer;
      CORBA_boolean _release;
   } CORBA_sequence_CORBA_long;
#endif
#if !defined(TC_IMPL_TC_CORBA_sequence_CORBA_long_0)
#define TC_IMPL_TC_CORBA_sequence_CORBA_long_0 'G'
#define TC_IMPL_TC_CORBA_sequence_CORBA_long_1 'N'
#define TC_IMPL_TC_CORBA_sequence_CORBA_long_2 'O'
#define TC_IMPL_TC_CORBA_sequence_CORBA_long_3 'M'
#define TC_IMPL_TC_CORBA_sequence_CORBA_long_4 'E'
#define TC_IMPL_TC_CORBA_sequence_CORBA_long_5 '_'
#define TC_IMPL_TC_CORBA_sequence_CORBA_long_6 'P'
#define TC_IMPL_TC_CORBA_sequence_CORBA_long_7 'a'
#define TC_IMPL_TC_CORBA_sequence_CORBA_long_8 'n'
#define TC_IMPL_TC_CORBA_sequence_CORBA_long_9 'e'
#define TC_IMPL_TC_CORBA_sequence_CORBA_long_10 'l'
#ifdef ORBIT_IDL_C_IMODULE_GNOME_Panel
   static
#else
   extern
#endif
   const struct CORBA_TypeCode_struct TC_CORBA_sequence_CORBA_long_struct;
#define TC_CORBA_sequence_CORBA_long ((CORBA_TypeCode)&TC_CORBA_sequence_CORBA_long_struct)
#endif
#define CORBA_sequence_CORBA_long__alloc() ((CORBA_sequence_CORBA_long *)ORBit_small_alloc (TC_CORBA_sequence_CORBA_long))
#define CORBA_sequence_CORBA_long__freekids(m,d) ORBit_small_freekids (TC_CORBA_sequence_CORBA_long,(m),(d))
#define CORBA_sequence_CORBA_long_allocbuf(l) ((CORBA_long*)ORBit_small_allocbuf (TC_CORBA_sequence_CORBA_long, (l)))
#define CORBA_sequence_CORBA_long_allocbuf(l) ((CORBA_long*)ORBit_small_allocbuf (TC_CORBA_sequence_CORBA_long, (l)))
#endif
#if !defined(_GNOME_Vertigo_SizeHintList_defined)
#define _GNOME_Vertigo_SizeHintList_defined 1
   typedef CORBA_sequence_CORBA_long GNOME_Vertigo_SizeHintList;
#define GNOME_Vertigo_SizeHintList_marshal(x,y,z) CORBA_sequence_CORBA_long_marshal((x),(y),(z))
#define GNOME_Vertigo_SizeHintList_demarshal(x,y,z,i) CORBA_sequence_CORBA_long_demarshal((x),(y),(z),(i))
#if !defined(TC_IMPL_TC_GNOME_Vertigo_SizeHintList_0)
#define TC_IMPL_TC_GNOME_Vertigo_SizeHintList_0 'G'
#define TC_IMPL_TC_GNOME_Vertigo_SizeHintList_1 'N'
#define TC_IMPL_TC_GNOME_Vertigo_SizeHintList_2 'O'
#define TC_IMPL_TC_GNOME_Vertigo_SizeHintList_3 'M'
#define TC_IMPL_TC_GNOME_Vertigo_SizeHintList_4 'E'
#define TC_IMPL_TC_GNOME_Vertigo_SizeHintList_5 '_'
#define TC_IMPL_TC_GNOME_Vertigo_SizeHintList_6 'P'
#define TC_IMPL_TC_GNOME_Vertigo_SizeHintList_7 'a'
#define TC_IMPL_TC_GNOME_Vertigo_SizeHintList_8 'n'
#define TC_IMPL_TC_GNOME_Vertigo_SizeHintList_9 'e'
#define TC_IMPL_TC_GNOME_Vertigo_SizeHintList_10 'l'
#ifdef ORBIT_IDL_C_IMODULE_GNOME_Panel
   static
#else
   extern
#endif
   const struct CORBA_TypeCode_struct TC_GNOME_Vertigo_SizeHintList_struct;
#define TC_GNOME_Vertigo_SizeHintList ((CORBA_TypeCode)&TC_GNOME_Vertigo_SizeHintList_struct)
#endif
#define GNOME_Vertigo_SizeHintList__alloc() ((GNOME_Vertigo_SizeHintList *)ORBit_small_alloc (TC_CORBA_sequence_CORBA_long))
#define GNOME_Vertigo_SizeHintList__freekids(m,d) ORBit_small_freekids (TC_CORBA_sequence_CORBA_long,(m),(d))
#define GNOME_Vertigo_SizeHintList_allocbuf(l) ((CORBA_long*)ORBit_small_allocbuf (TC_CORBA_sequence_CORBA_long, (l)))
#endif
#if !defined(_GNOME_Vertigo_PanelBackground_defined)
#define _GNOME_Vertigo_PanelBackground_defined 1
   typedef CORBA_string GNOME_Vertigo_PanelBackground;
#define GNOME_Vertigo_PanelBackground_marshal(x,y,z) CORBA_string_marshal((x),(y),(z))
#define GNOME_Vertigo_PanelBackground_demarshal(x,y,z,i) CORBA_string_demarshal((x),(y),(z),(i))
#if !defined(TC_IMPL_TC_GNOME_Vertigo_PanelBackground_0)
#define TC_IMPL_TC_GNOME_Vertigo_PanelBackground_0 'G'
#define TC_IMPL_TC_GNOME_Vertigo_PanelBackground_1 'N'
#define TC_IMPL_TC_GNOME_Vertigo_PanelBackground_2 'O'
#define TC_IMPL_TC_GNOME_Vertigo_PanelBackground_3 'M'
#define TC_IMPL_TC_GNOME_Vertigo_PanelBackground_4 'E'
#define TC_IMPL_TC_GNOME_Vertigo_PanelBackground_5 '_'
#define TC_IMPL_TC_GNOME_Vertigo_PanelBackground_6 'P'
#define TC_IMPL_TC_GNOME_Vertigo_PanelBackground_7 'a'
#define TC_IMPL_TC_GNOME_Vertigo_PanelBackground_8 'n'
#define TC_IMPL_TC_GNOME_Vertigo_PanelBackground_9 'e'
#define TC_IMPL_TC_GNOME_Vertigo_PanelBackground_10 'l'
#ifdef ORBIT_IDL_C_IMODULE_GNOME_Panel
   static
#else
   extern
#endif
   const struct CORBA_TypeCode_struct TC_GNOME_Vertigo_PanelBackground_struct;
#define TC_GNOME_Vertigo_PanelBackground ((CORBA_TypeCode)&TC_GNOME_Vertigo_PanelBackground_struct)
#endif
#define GNOME_Vertigo_PanelBackground__alloc() ((GNOME_Vertigo_PanelBackground *)ORBit_small_alloc (TC_CORBA_string))
#define GNOME_Vertigo_PanelBackground__freekids(m,d) ORBit_small_freekids (TC_CORBA_string,(m),(d))
#endif
#if !defined(ORBIT_DECL_GNOME_Vertigo_PanelShell) && !defined(_GNOME_Vertigo_PanelShell_defined)
#define ORBIT_DECL_GNOME_Vertigo_PanelShell 1
#define _GNOME_Vertigo_PanelShell_defined 1
#define GNOME_Vertigo_PanelShell__freekids CORBA_Object__freekids
   typedef CORBA_Object GNOME_Vertigo_PanelShell;
   extern CORBA_unsigned_long GNOME_Vertigo_PanelShell__classid;
#if !defined(TC_IMPL_TC_GNOME_Vertigo_PanelShell_0)
#define TC_IMPL_TC_GNOME_Vertigo_PanelShell_0 'G'
#define TC_IMPL_TC_GNOME_Vertigo_PanelShell_1 'N'
#define TC_IMPL_TC_GNOME_Vertigo_PanelShell_2 'O'
#define TC_IMPL_TC_GNOME_Vertigo_PanelShell_3 'M'
#define TC_IMPL_TC_GNOME_Vertigo_PanelShell_4 'E'
#define TC_IMPL_TC_GNOME_Vertigo_PanelShell_5 '_'
#define TC_IMPL_TC_GNOME_Vertigo_PanelShell_6 'P'
#define TC_IMPL_TC_GNOME_Vertigo_PanelShell_7 'a'
#define TC_IMPL_TC_GNOME_Vertigo_PanelShell_8 'n'
#define TC_IMPL_TC_GNOME_Vertigo_PanelShell_9 'e'
#define TC_IMPL_TC_GNOME_Vertigo_PanelShell_10 'l'
#ifdef ORBIT_IDL_C_IMODULE_GNOME_Panel
   static
#else
   extern
#endif
   const struct CORBA_TypeCode_struct TC_GNOME_Vertigo_PanelShell_struct;
#define TC_GNOME_Vertigo_PanelShell ((CORBA_TypeCode)&TC_GNOME_Vertigo_PanelShell_struct)
#endif
#endif
#if !defined(ORBIT_DECL_GNOME_Vertigo_PanelAppletShell) && !defined(_GNOME_Vertigo_PanelAppletShell_defined)
#define ORBIT_DECL_GNOME_Vertigo_PanelAppletShell 1
#define _GNOME_Vertigo_PanelAppletShell_defined 1
#define GNOME_Vertigo_PanelAppletShell__freekids CORBA_Object__freekids
   typedef CORBA_Object GNOME_Vertigo_PanelAppletShell;
   extern CORBA_unsigned_long GNOME_Vertigo_PanelAppletShell__classid;
#if !defined(TC_IMPL_TC_GNOME_Vertigo_PanelAppletShell_0)
#define TC_IMPL_TC_GNOME_Vertigo_PanelAppletShell_0 'G'
#define TC_IMPL_TC_GNOME_Vertigo_PanelAppletShell_1 'N'
#define TC_IMPL_TC_GNOME_Vertigo_PanelAppletShell_2 'O'
#define TC_IMPL_TC_GNOME_Vertigo_PanelAppletShell_3 'M'
#define TC_IMPL_TC_GNOME_Vertigo_PanelAppletShell_4 'E'
#define TC_IMPL_TC_GNOME_Vertigo_PanelAppletShell_5 '_'
#define TC_IMPL_TC_GNOME_Vertigo_PanelAppletShell_6 'P'
#define TC_IMPL_TC_GNOME_Vertigo_PanelAppletShell_7 'a'
#define TC_IMPL_TC_GNOME_Vertigo_PanelAppletShell_8 'n'
#define TC_IMPL_TC_GNOME_Vertigo_PanelAppletShell_9 'e'
#define TC_IMPL_TC_GNOME_Vertigo_PanelAppletShell_10 'l'
#ifdef ORBIT_IDL_C_IMODULE_GNOME_Panel
   static
#else
   extern
#endif
   const struct CORBA_TypeCode_struct
      TC_GNOME_Vertigo_PanelAppletShell_struct;
#define TC_GNOME_Vertigo_PanelAppletShell ((CORBA_TypeCode)&TC_GNOME_Vertigo_PanelAppletShell_struct)
#endif
#endif

/** POA structures **/
#ifndef _defined_POA_GNOME_Vertigo_PanelShell
#define _defined_POA_GNOME_Vertigo_PanelShell 1
   typedef struct
   {
      void *_private;
      void (*displayRunDialog) (PortableServer_Servant _servant,
				const CORBA_char * initialString,
				CORBA_Environment * ev);
   } POA_GNOME_Vertigo_PanelShell__epv;
   typedef struct
   {
      PortableServer_ServantBase__epv *_base_epv;
      POA_Bonobo_Unknown__epv *Bonobo_Unknown_epv;
      POA_GNOME_Vertigo_PanelShell__epv *GNOME_Vertigo_PanelShell_epv;
   } POA_GNOME_Vertigo_PanelShell__vepv;
   typedef struct
   {
      void *_private;
      POA_GNOME_Vertigo_PanelShell__vepv *vepv;
   } POA_GNOME_Vertigo_PanelShell;
   extern void POA_GNOME_Vertigo_PanelShell__init(PortableServer_Servant
						  servant,
						  CORBA_Environment * ev);
   extern void POA_GNOME_Vertigo_PanelShell__fini(PortableServer_Servant
						  servant,
						  CORBA_Environment * ev);
#endif				/* _defined_POA_GNOME_Vertigo_PanelShell */
#ifndef _defined_POA_GNOME_Vertigo_PanelAppletShell
#define _defined_POA_GNOME_Vertigo_PanelAppletShell 1
   typedef struct
   {
      void *_private;
      void (*popup_menu) (PortableServer_Servant _servant,
			  const CORBA_long button, const CORBA_long time,
			  CORBA_Environment * ev);
   } POA_GNOME_Vertigo_PanelAppletShell__epv;
   typedef struct
   {
      PortableServer_ServantBase__epv *_base_epv;
      POA_Bonobo_Unknown__epv *Bonobo_Unknown_epv;
      POA_GNOME_Vertigo_PanelAppletShell__epv
	 *GNOME_Vertigo_PanelAppletShell_epv;
   } POA_GNOME_Vertigo_PanelAppletShell__vepv;
   typedef struct
   {
      void *_private;
      POA_GNOME_Vertigo_PanelAppletShell__vepv *vepv;
   } POA_GNOME_Vertigo_PanelAppletShell;
   extern void POA_GNOME_Vertigo_PanelAppletShell__init(PortableServer_Servant
							servant,
							CORBA_Environment *
							ev);
   extern void POA_GNOME_Vertigo_PanelAppletShell__fini(PortableServer_Servant
							servant,
							CORBA_Environment *
							ev);
#endif				/* _defined_POA_GNOME_Vertigo_PanelAppletShell */

/** skel prototypes **/
   void
      _ORBIT_skel_small_GNOME_Vertigo_PanelShell_displayRunDialog
      (POA_GNOME_Vertigo_PanelShell * _ORBIT_servant, gpointer _ORBIT_retval,
       gpointer * _ORBIT_args, CORBA_Context ctx, CORBA_Environment * ev,
       void (*_impl_displayRunDialog) (PortableServer_Servant _servant,
				       const CORBA_char * initialString,
				       CORBA_Environment * ev));
   void
      _ORBIT_skel_small_GNOME_Vertigo_PanelAppletShell_popup_menu
      (POA_GNOME_Vertigo_PanelAppletShell * _ORBIT_servant,
       gpointer _ORBIT_retval, gpointer * _ORBIT_args, CORBA_Context ctx,
       CORBA_Environment * ev,
       void (*_impl_popup_menu) (PortableServer_Servant _servant,
				 const CORBA_long button,
				 const CORBA_long time,
				 CORBA_Environment * ev));

/** stub prototypes **/
#define GNOME_Vertigo_PanelShell_ref Bonobo_Unknown_ref
#define GNOME_Vertigo_PanelShell_unref Bonobo_Unknown_unref
#define GNOME_Vertigo_PanelShell_queryInterface Bonobo_Unknown_queryInterface
   void GNOME_Vertigo_PanelShell_displayRunDialog(GNOME_Vertigo_PanelShell
						  _obj,
						  const CORBA_char *
						  initialString,
						  CORBA_Environment * ev);
#define GNOME_Vertigo_PanelAppletShell_ref Bonobo_Unknown_ref
#define GNOME_Vertigo_PanelAppletShell_unref Bonobo_Unknown_unref
#define GNOME_Vertigo_PanelAppletShell_queryInterface Bonobo_Unknown_queryInterface
   void
      GNOME_Vertigo_PanelAppletShell_popup_menu(GNOME_Vertigo_PanelAppletShell
						_obj, const CORBA_long button,
						const CORBA_long time,
						CORBA_Environment * ev);
#include <orbit/orb-core/orbit-interface.h>

#ifdef ORBIT_IDL_C_IMODULE_GNOME_Panel
   static
#else
   extern
#endif
   ORBit_IInterface GNOME_Vertigo_PanelShell__iinterface;
#define GNOME_Vertigo_PanelShell_IMETHODS_LEN 1
#ifdef ORBIT_IDL_C_IMODULE_GNOME_Panel
   static
#else
   extern
#endif
   ORBit_IMethod
      GNOME_Vertigo_PanelShell__imethods
      [GNOME_Vertigo_PanelShell_IMETHODS_LEN];
#ifdef ORBIT_IDL_C_IMODULE_GNOME_Panel
   static
#else
   extern
#endif
   ORBit_IInterface GNOME_Vertigo_PanelAppletShell__iinterface;
#define GNOME_Vertigo_PanelAppletShell_IMETHODS_LEN 1
#ifdef ORBIT_IDL_C_IMODULE_GNOME_Panel
   static
#else
   extern
#endif
   ORBit_IMethod
      GNOME_Vertigo_PanelAppletShell__imethods
      [GNOME_Vertigo_PanelAppletShell_IMETHODS_LEN];
#ifdef __cplusplus
}
#endif				/* __cplusplus */

#ifndef EXCLUDE_ORBIT_H
#include <orbit/orbit.h>

#endif				/* EXCLUDE_ORBIT_H */
#endif
#undef ORBIT_IDL_SERIAL
