#ifndef __CFL_ENUMS_H__
#define __CFL_ENUMS_H__

static const char *Fl_EventNames[] = {
    "Fl_Event_None",
    "Fl_Event_Push",
    "Fl_Event_Released",
    "Fl_Event_Enter",
    "Fl_Event_Leave",
    "Fl_Event_Drag",
    "Fl_Event_Focus",
    "Fl_Event_Unfocus",
    "Fl_Event_KeyDown",
    "Fl_Event_KeyUp",
    "Fl_Event_Close",
    "Fl_Event_Move",
    "Fl_Event_Shortcut",
    "Fl_Event_Deactivate",
    "Fl_Event_Activate",
    "Fl_Event_Hide",
    "Fl_Event_Show",
    "Fl_Event_Paste",
    "Fl_Event_SelectionClear",
    "Fl_Event_MouseWheel",
    "Fl_Event_DndEnter",
    "Fl_Event_DndDrag",
    "Fl_Event_DndLeave",
    "Fl_Event_DndRelease",
    "Fl_Event_ScreenConfigChanged",
    "Fl_Event_Fullscreen",
    "Fl_Event_ZoomGesture",
    "Fl_Event_ZoomEvent",
    "Fl_Event_Resize",
};

enum Fl_BrowserType {
    Fl_BrowserType_Normal = 0,
    Fl_BrowserType_Select = 1,
    Fl_BrowserType_Hold   = 2,
    Fl_BrowserType_Multi  = 3,
};

enum Fl_BrowserScrollbar {
    Fl_BrowserScrollbar_None             = 0,
    Fl_BrowserScrollbar_Horizontal       = 1,
    Fl_BrowserScrollbar_Vertical         = 2,
    Fl_BrowserScrollbar_Both             = 3,
    Fl_BrowserScrollbar_AlwaysOn         = 4,
    Fl_BrowserScrollbar_HorizontalAlways = 5,
    Fl_BrowserScrollbar_VerticalAlways   = 6,
    Fl_BrowserScrollbar_BothAlways       = 7,
};

enum Fl_FileType {
    Fl_FileType_Files = 0,
    Fl_FileType_Dirs,
};

enum Fl_ButtonType {
    Fl_ButtonType_Normal = 0,
    Fl_ButtonType_Toggle = 1,
    Fl_ButtonType_Radio  = 102,
    Fl_ButtonType_Hidden = 3,
};

enum Fl_FileDialogType {
    Fl_FileDialogType_BrowseFile = 0,
    Fl_FileDialogType_BrowseDir,
    Fl_FileDialogType_BrowseMultiFile,
    Fl_FileDialogType_BrowseMultiDir,
    Fl_FileDialogType_BrowseSaveFile,
    Fl_FileDialogType_BrowseSaveDir,
};

enum Fl_FileDialogOptions {
    Fl_FileDialogOptions_NoOptions     = 0,
    Fl_FileDialogOptions_SaveAsConfirm = 1,
    Fl_FileDialogOptions_NewFolder     = 2,
    Fl_FileDialogOptions_Preview       = 4,
    Fl_FileDialogOptions_UseFilterExt  = 8,
};

enum Fl_BeepType {
    Fl_BeepType_Default = 0,
    Fl_BeepType_Message,
    Fl_BeepType_Error,
    Fl_BeepType_Question,
    Fl_BeepType_Password,
    Fl_BeepType_Notification,
};

enum Fl_FileChooserType {
    Fl_FileChooserType_Single    = 0,
    Fl_FileChooserType_Multi     = 1,
    Fl_FileChooserType_Create    = 2,
    Fl_FileChooserType_Directory = 4,
};

enum Fl_LineStyle {
    Fl_LineStyle_Solid = 0,
    Fl_LineStyle_Dash,
    Fl_LineStyle_Dot,
    Fl_LineStyle_DashDot,
    Fl_LineStyle_DashDotDot,
    Fl_LineStyle_CapFlat   = 100,
    Fl_LineStyle_CapRound  = 200,
    Fl_LineStyle_CapSquare = 300,
    Fl_LineStyle_JoinMiter = 1000,
    Fl_LineStyle_JoinRound = 2000,
    Fl_LineStyle_JoinBevel = 3000,
};

enum Fl_LabelType {
    Fl_LabelType_Normal = 0,
    Fl_LabelType_None,
    Fl_LabelType_Shadow,
    Fl_LabelType_Engraved,
    Fl_LabelType_Embossed,
    Fl_LabelType_Multi,
    Fl_LabelType_Icon,
    Fl_LabelType_Image,
    Fl_LabelType_FreeType,
};

enum Fl_BoxType {
    Fl_BoxType_NoBox = 0,
    Fl_BoxType_FlatBox,
    Fl_BoxType_UpBox,
    Fl_BoxType_DownBox,
    Fl_BoxType_UpFrame,
    Fl_BoxType_DownFrame,
    Fl_BoxType_ThinUpBox,
    Fl_BoxType_ThinDownBox,
    Fl_BoxType_ThinUpFrame,
    Fl_BoxType_ThinDownFrame,
    Fl_BoxType_EngraveBox,
    Fl_BoxType_EmbossedBox,
    Fl_BoxType_EngravedFrame,
    Fl_BoxType_EmbossedFrame,
    Fl_BoxType_BorderBox,
    Fl_BoxType_ShadowBox,
    Fl_BoxType_BorderFrame,
    Fl_BoxType_ShadowFrame,
    Fl_BoxType_RoundedBox,
    Fl_BoxType_RShadowBox,
    Fl_BoxType_RoundedFrame,
    Fl_BoxType_RFlatBox,
    Fl_BoxType_RoundUpBox,
    Fl_BoxType_RoundDownBox,
    Fl_BoxType_DiamondUpBox,
    Fl_BoxType_DiamondDownBox,
    Fl_BoxType_OvalBox,
    Fl_BoxType_OShadowBox,
    Fl_BoxType_OvalFrame,
    Fl_BoxType_OFlatBox,
    Fl_BoxType_PlasticUpBox,
    Fl_BoxType_PlasticDownBox,
    Fl_BoxType_PlasticUpFrame,
    Fl_BoxType_PlasticDownFrame,
    Fl_BoxType_PlasticThinUpBox,
    Fl_BoxType_PlasticThinDownBox,
    Fl_BoxType_PlasticRoundUpBox,
    Fl_BoxType_PlasticRoundDownBox,
    Fl_BoxType_GtkUpBox,
    Fl_BoxType_GtkDownBox,
    Fl_BoxType_GtkUpFrame,
    Fl_BoxType_GtkDownFrame,
    Fl_BoxType_GtkThinUpBox,
    Fl_BoxType_GtkThinDownBox,
    Fl_BoxType_GtkThinUpFrame,
    Fl_BoxType_GtkThinDownFrame,
    Fl_BoxType_GtkRoundUpFrame,
    Fl_BoxType_GtkRoundDownFrame,
    Fl_BoxType_GleamUpBox,
    Fl_BoxType_GleamDownBox,
    Fl_BoxType_GleamUpFrame,
    Fl_BoxType_GleamDownFrame,
    Fl_BoxType_GleamThinUpBox,
    Fl_BoxType_GleamThinDownBox,
    Fl_BoxType_GleamRoundUpBox,
    Fl_BoxType_GleamRoundDownBox,
    Fl_BoxType_FreeBoxType,
};

enum Fl_Align {
    Fl_Align_Center          = 0x0000,
    Fl_Align_Top             = 0x0001,
    Fl_Align_Bottom          = 0x0002,
    Fl_Align_Left            = 0x0004,
    Fl_Align_Right           = 0x0008,
    Fl_Align_Inside          = 0x0010,
    Fl_Align_TextOverImage   = 0x0020,
    Fl_Align_ImageOverText   = 0x000,
    Fl_Align_NoWrap          = 0x000,
    Fl_Align_Clip            = 0x0040,
    Fl_Align_Wrap            = 0x0080,
    Fl_Align_ImageNextToText = 0x0100,
    Fl_Align_TextNextToImage = 0x0120,
    Fl_Align_ImageBackdrop   = 0x0200,
    Fl_Align_TopLeft         = 0x0001 | 0x0004,
    Fl_Align_TopRight        = 0x0001 | 0x0008,
    Fl_Align_BottomLeft      = 0x0002 | 0x0004,
    Fl_Align_BottomRight     = 0x0002 | 0x0008,
    Fl_Align_LeftTop         = 0x0007,
    Fl_Align_RightTop        = 0x000B,
    Fl_Align_LeftBottom      = 0x000D,
    Fl_Align_RightBottom     = 0x000E,
    Fl_Align_PositionMask    = 0x000F,
    Fl_Align_ImageMask       = 0x0320,
};

enum Fl_Font {
    Fl_Font_Helvetica           = 0,
    Fl_Font_HelveticaBold       = 1,
    Fl_Font_HelveticaItalic     = 2,
    Fl_Font_HelveticaBoldItalic = 3,
    Fl_Font_Courier             = 4,
    Fl_Font_CourierBold         = 5,
    Fl_Font_CourierItalic       = 6,
    Fl_Font_CourierBoldItalic   = 7,
    Fl_Font_Times               = 8,
    Fl_Font_TimesBold           = 9,
    Fl_Font_TimesItalic         = 10,
    Fl_Font_TimesBoldItalic     = 11,
    Fl_Font_Symbol              = 12,
    Fl_Font_Screen              = 13,
    Fl_Font_ScreenBold          = 14,
    Fl_Font_Zapfdingbats        = 15,
};

enum Fl_Color {
    Fl_Color_ForeGround   = 0,
    Fl_Color_Foreground   = 0,
    Fl_Color_BackGround2  = 7,
    Fl_Color_Background2  = 7,
    Fl_Color_Inactive     = 8,
    Fl_Color_Selection    = 15,
    Fl_Color_Gray0        = 32,
    Fl_Color_Dark3        = 39,
    Fl_Color_Dark2        = 45,
    Fl_Color_Dark1        = 47,
    Fl_Color_FrameDefault = 49,
    Fl_Color_BackGround   = 49,
    Fl_Color_Background   = 49,
    Fl_Color_Light1       = 50,
    Fl_Color_Light2       = 52,
    Fl_Color_Light3       = 54,
    Fl_Color_Black        = 56,
    Fl_Color_Red          = 88,
    Fl_Color_Green        = 63,
    Fl_Color_Yellow       = 95,
    Fl_Color_Blue         = 216,
    Fl_Color_Magenta      = 248,
    Fl_Color_Cyan         = 223,
    Fl_Color_DarkRed      = 72,
    Fl_Color_DarkGreen    = 60,
    Fl_Color_DarkYellow   = 76,
    Fl_Color_DarkBlue     = 136,
    Fl_Color_DarkMagenta  = 152,
    Fl_Color_DarkCyan     = 140,
    Fl_Color_White        = 255,
};

enum Fl_Event {
    Fl_Event_None = 0,
    Fl_Event_Push,
    Fl_Event_Released,
    Fl_Event_Enter,
    Fl_Event_Leave,
    Fl_Event_Drag,
    Fl_Event_Focus,
    Fl_Event_Unfocus,
    Fl_Event_KeyDown,
    Fl_Event_KeyUp,
    Fl_Event_Close,
    Fl_Event_Move,
    Fl_Event_Shortcut,
    Fl_Event_Deactivate,
    Fl_Event_Activate,
    Fl_Event_Hide,
    Fl_Event_Show,
    Fl_Event_Paste,
    Fl_Event_SelectionClear,
    Fl_Event_MouseWheel,
    Fl_Event_DndEnter,
    Fl_Event_DndDrag,
    Fl_Event_DndLeave,
    Fl_Event_DndRelease,
    Fl_Event_ScreenConfigChanged,
    Fl_Event_Fullscreen,
    Fl_Event_ZoomGesture,
    Fl_Event_ZoomEvent,
    Fl_Event_Resize,
};

enum Fl_Key {
    Fl_Key_None          = 0,
    Fl_Key_Button        = 0xfee8,
    Fl_Key_BackSpace     = 0xff08,
    Fl_Key_Tab           = 0xff09,
    Fl_Key_IsoKey        = 0xff0c,
    Fl_Key_Enter         = 0xff0d,
    Fl_Key_Pause         = 0xff13,
    Fl_Key_ScrollLock    = 0xff14,
    Fl_Key_Escape        = 0xff1b,
    Fl_Key_Kana          = 0xff2e,
    Fl_Key_Eisu          = 0xff2f,
    Fl_Key_Yen           = 0xff30,
    Fl_Key_JISUnderscore = 0xff31,
    Fl_Key_Home          = 0xff50,
    Fl_Key_Left          = 0xff51,
    Fl_Key_Up            = 0xff52,
    Fl_Key_Right         = 0xff53,
    Fl_Key_Down          = 0xff54,
    Fl_Key_PageUp        = 0xff55,
    Fl_Key_PageDown      = 0xff56,
    Fl_Key_End           = 0xff57,
    Fl_Key_Print         = 0xff61,
    Fl_Key_Insert        = 0xff63,
    Fl_Key_Menu          = 0xff67,
    Fl_Key_Help          = 0xff68,
    Fl_Key_NumLock       = 0xff7f,
    Fl_Key_KP            = 0xff80,
    Fl_Key_KPEnter       = 0xff8d,
    Fl_Key_KPLast        = 0xffbd,
    Fl_Key_F1            = 0xffbd + 1,
    Fl_Key_F2            = 0xffbd + 2,
    Fl_Key_F3            = 0xffbd + 3,
    Fl_Key_F4            = 0xffbd + 4,
    Fl_Key_F5            = 0xffbd + 5,
    Fl_Key_F6            = 0xffbd + 6,
    Fl_Key_F7            = 0xffbd + 7,
    Fl_Key_F8            = 0xffbd + 8,
    Fl_Key_F9            = 0xffbd + 9,
    Fl_Key_F10           = 0xffbd + 10,
    Fl_Key_F11           = 0xffbd + 11,
    Fl_Key_F12           = 0xffbd + 12,
    Fl_Key_FLast         = 0xffe0,
    Fl_Key_ShiftL        = 0xffe1,
    Fl_Key_ShiftR        = 0xffe2,
    Fl_Key_ControlL      = 0xffe3,
    Fl_Key_ControlR      = 0xffe4,
    Fl_Key_CapsLock      = 0xffe5,
    Fl_Key_MetaL         = 0xffe7,
    Fl_Key_MetaR         = 0xffe8,
    Fl_Key_AltL          = 0xffe9,
    Fl_Key_AltR          = 0xffea,
    Fl_Key_Delete        = 0xffff,
};

enum Fl_Shortcut {
    Fl_Shortcut_None     = 0,
    Fl_Shortcut_Shift    = 0x00010000,
    Fl_Shortcut_CapsLock = 0x00020000,
    Fl_Shortcut_Ctrl     = 0x00040000,
    Fl_Shortcut_Alt      = 0x00080000,
    Fl_Shortcut_Meta     = 0x00400000,
    Fl_Shortcut_Button1  = 0x01000000,
    Fl_Shortcut_Button2  = 0x02000000,
    Fl_Shortcut_Button3  = 0x04000000,
    Fl_Shortcut_Buttons  = 0x7f000000,
};

enum Fl_CallbackTrigger {
    Fl_CallbackTrigger_Never           = 0,
    Fl_CallbackTrigger_Changed         = 1,
    Fl_CallbackTrigger_NotChanged      = 2,
    Fl_CallbackTrigger_Release         = 4,
    Fl_CallbackTrigger_ReleaseAlways   = 6,
    Fl_CallbackTrigger_EnterKey        = 8,
    Fl_CallbackTrigger_EnterKeyAlways  = 10,
    Fl_CallbackTrigger_EnterKeyChanged = 11,
};

enum Fl_TextCursor {
    Fl_TextCursor_Normal,
    Fl_TextCursor_Caret,
    Fl_TextCursor_Dim,
    Fl_TextCursor_Block,
    Fl_TextCursor_Heavy,
    Fl_TextCursor_Simple,
};

enum Fl_Cursor {
    Fl_Cursor_Default = 0,
    Fl_Cursor_Arrow   = 35,
    Fl_Cursor_Cross   = 66,
    Fl_Cursor_Wait    = 76,
    Fl_Cursor_Insert  = 77,
    Fl_Cursor_Hand    = 31,
    Fl_Cursor_Help    = 47,
    Fl_Cursor_Move    = 27,
    Fl_Cursor_NS      = 78,
    Fl_Cursor_WE      = 79,
    Fl_Cursor_NWSE    = 80,
    Fl_Cursor_NESW    = 81,
    Fl_Cursor_N       = 70,
    Fl_Cursor_NE      = 69,
    Fl_Cursor_E       = 49,
    Fl_Cursor_SE      = 8,
    Fl_Cursor_S       = 9,
    Fl_Cursor_SW      = 7,
    Fl_Cursor_W       = 36,
    Fl_Cursor_NW      = 68,
    Fl_Cursor_None    = 255,
};

enum Fl_Mode {
    Fl_Mode_Rgb         = 0,
    Fl_Mode_Index       = 1,
    Fl_Mode_Double      = 2,
    Fl_Mode_Accum       = 4,
    Fl_Mode_Alpha       = 8,
    Fl_Mode_Depth       = 16,
    Fl_Mode_Stencil     = 32,
    Fl_Mode_Rgb8        = 64,
    Fl_Mode_MultiSample = 128,
    Fl_Mode_Stereo      = 256,
    Fl_Mode_FakeSingle  = 512,
    Fl_Mode_Opengl3     = 1024,
};

enum Fl_PackType {
    Fl_PackType_Vertical   = 0,
    Fl_PackType_Horizontal = 1,
};

enum Fl_ScrollType {
    Fl_ScrollType_None             = 0,
    Fl_ScrollType_Horizontal       = 1,
    Fl_ScrollType_Vertical         = 2,
    Fl_ScrollType_Both             = 3,
    Fl_ScrollType_AlwaysOn         = 4,
    Fl_ScrollType_HorizontalAlways = 5,
    Fl_ScrollType_VerticalAlways   = 6,
    Fl_ScrollType_BothAlways       = 7,
};

enum Fl_InputType {
    Fl_InputType_Normal    = 0,
    Fl_InputType_Float     = 1,
    Fl_InputType_Int       = 2,
    Fl_InputType_Multiline = 4,
    Fl_InputType_Secret    = 5,
    Fl_InputType_Input     = 7,
    Fl_InputType_Readonly  = 8,
    Fl_InputType_Wrap      = 16,
};

enum Fl_OutputType {
    Fl_OutputType_Normal    = 8,
    Fl_OutputType_Multiline = 12,
};

enum Fl_MenuFlag {
    Fl_MenuFlag_Normal         = 0,
    Fl_MenuFlag_Inactive       = 1,
    Fl_MenuFlag_Toggle         = 2,
    Fl_MenuFlag_Value          = 4,
    Fl_MenuFlag_Radio          = 8,
    Fl_MenuFlag_Invisible      = 0x10,
    Fl_MenuFlag_SubmenuPointer = 0x20,
    Fl_MenuFlag_Submenu        = 0x40,
    Fl_MenuFlag_MenuDivider    = 0x80,
    Fl_MenuFlag_MenuHorizontal = 0x100,
};

enum Fl_ChartType {
    Fl_ChartType_Bar           = 0,
    Fl_ChartType_HorizontalBar = 1,
    Fl_ChartType_Line          = 2,
    Fl_ChartType_Fill          = 3,
    Fl_ChartType_Spike         = 4,
    Fl_ChartType_Pie           = 5,
    Fl_ChartType_SpecialPie    = 6,
};

enum Fl_ClockType {
    Fl_ClockType_Square = 0,
    Fl_ClockType_Round  = 1,
};

enum Fl_TableContext {
    Fl_TableContext_None      = 0,
    Fl_TableContext_StartPage = 0x01,
    Fl_TableContext_EndPage   = 0x02,
    Fl_TableContext_RowHeader = 0x04,
    Fl_TableContext_ColHeader = 0x08,
    Fl_TableContext_Cell      = 0x10,
    Fl_TableContext_Table     = 0x20,
    Fl_TableContext_RcResize  = 0x40,
};

enum Fl_TableRowSelectMode {
    Fl_TableRowSelectMode_None,
    Fl_TableRowSelectMode_Single,
    Fl_TableRowSelectMode_Multi,
};

enum Fl_TreeSort {
    Fl_TreeSort_None       = 0,
    Fl_TreeSort_Ascending  = 1,
    Fl_TreeSort_Descending = 2,
};

enum Fl_TreeConnectorStyle {
    Fl_TreeConnectorStyle_None   = 0,
    Fl_TreeConnectorStyle_Dotted = 1,
    Fl_TreeConnectorStyle_Solid  = 2,
};

enum Fl_TreeSelect {
    Fl_TreeSelect_None            = 0,
    Fl_TreeSelect_Single          = 1,
    Fl_TreeSelect_Multi           = 2,
    Fl_TreeSelect_SingleDraggable = 3,
};

enum Fl_TreeItemSelect {
    Fl_TreeItemSelect_Deselect = 0,
    Fl_TreeItemSelect_Select   = 1,
    Fl_TreeItemSelect_Toggle   = 2,
};

enum Fl_TreeReason {
    Fl_TreeReason_None = 0,
    Fl_TreeReason_Selected,
    Fl_TreeReason_Deselected,
    Fl_TreeReason_Reselected,
    Fl_TreeReason_Opened,
    Fl_TreeReason_Closed,
    Fl_TreeReason_Dragged,
};

enum Fl_TreeItemReselectMode {
    Fl_TreeItemReselectMode_Once = 0,
    Fl_TreeItemReselectMode_Always,
};

enum Fl_TreeItemDrawMode {
    Fl_TreeItemDrawMode_Default          = 0,
    Fl_TreeItemDrawMode_LabelAndWidget   = 1,
    Fl_TreeItemDrawMode_HeightFromWidget = 2,
};

enum Fl_SliderType {
    Fl_SliderType_Vertical       = 0,
    Fl_SliderType_Horizontal     = 1,
    Fl_SliderType_VerticalFill   = 2,
    Fl_SliderType_HorizontalFill = 3,
    Fl_SliderType_VerticalNice   = 4,
    Fl_SliderType_HorizontalNice = 5,
};

enum Fl_DialType {
    Fl_DialType_Normal = 0,
    Fl_DialType_Line   = 1,
    Fl_DialType_Fill   = 2,
};

enum Fl_CounterType {
    Fl_CounterType_Normal = 0,
    Fl_CounterType_Simple = 1,
};

enum Fl_ScrollbarType {
    Fl_ScrollbarType_Vertical       = 0,
    Fl_ScrollbarType_Horizontal     = 1,
    Fl_ScrollbarType_VerticalFill   = 2,
    Fl_ScrollbarType_HorizontalFill = 3,
    Fl_ScrollbarType_VerticalNice   = 4,
    Fl_ScrollbarType_HorizontalNice = 5,
};

enum Fl_WindowType {
    Fl_WindowType_Normal = 240,
    Fl_WindowType_Double = 241,
};

enum Fl_WrapMode {
    Fl_Wrap_None,
    Fl_Wrap_At_Column,
    Fl_Wrap_At_Pixel,
    Fl_Wrap_At_Bounds,
};

enum Fl_DragType {
    Fl_Drag_None      = -2,
    Fl_Drag_Start_Dnd = -1,
    Fl_Drag_Char      = 0,
    Fl_Drag_Word      = 1,
    Fl_Drag_Line      = 2,
};

enum Fl_Damage {
    Fl_Damage_Child   = 0x01, /**< A child needs to be redrawn. */
    Fl_Damage_Expose  = 0x02, /**< The window was exposed. */
    Fl_Damage_Scroll  = 0x04, /**< The Fl_Scroll widget was scrolled. */
    Fl_Damage_Overlay = 0x08, /**< The overlay planes need to be redrawn. */
    Fl_Damage_User1   = 0x10, /**< First user-defined damage bit. */
    Fl_Damage_User2   = 0x20, /**< Second user-defined damage bit. */
    Fl_Damage_All     = 0x80  /**< Everything needs to be redrawn. */
};

enum Fl_MenuButtonType {
    Popup1 = 1,
    Popup2,
    Popup12,
    Popup3,
    Popup13,
    Popup23,
    Popup123,
};

enum Fl_FlexType {
    Fl_FlexType_Row = 0,
    Fl_FlexType_Column,
};

enum Fl_RgbScaling {
    Fl_RgbScaling_Nearest = 0,
    Fl_RgbScaling_Bilinear,
};

enum Fl_Table_ResizeFlag {
    Fl_Table_RESIZE_NONE      = 0,
    Fl_Table_RESIZE_COL_LEFT  = 1,
    Fl_Table_RESIZE_COL_RIGHT = 2,
    Fl_Table_RESIZE_ROW_ABOVE = 3,
    Fl_Table_RESIZE_ROW_BELOW = 4
};

#endif
