/*
 * Axiomtek SBC8a361 API Library
 * User-Mode Driver	
 * Wrote by jrtiger.lee@axiomtek.com.tw
 */

/* Library ==> /usr/lib/lib8a361.so.1.0.0 */

/* Library ==> /usr/lib/lib8a552.so.1.0.0 */

/* NA361 Have 1 (Max) Slot, Every Slot Have 1 ~ 4(Max) Segment for Lanypass */

/****************************************************/
/* CPLD Control LAN by-pass With PC Power On */
/* int slot_no : select slot = 1 or 2 or 3          */
/* onoff:  enable = 1   disable = 0                 */
int _8a361_set_pcon_lan_by_pass(int slot_no, unsigned char selseg, int onoff);
/****************************************************/
/* CPLD Control LAN by-pass With PC Power Off*/
/* onoff:  enable = 1   disable = 0                 */
int _8a361_set_pcoff_lan_by_pass( int slot_no, unsigned char selseg, int onoff);
/****************************************************/
/* CPLD Control LAN by-pass With Timer              */
/* timeset:  1=1second 2=2second 3=4second ..       */
int _8a361_set_timer_lan_by_pass( int slot_no, unsigned char selseg, unsigned char timeset );
/****************************************************/
/* Get Expired Flag of LAN by-pass With Timer       */
/* return :  1=expired  0=not expired               */
int _8a361_get_timer_expireflag( int slot_no);
/****************************************************/
/* Get Status Of CPLD Control LAN by-pass   */
/* return 1: LAN by-pass Enable  0: by-pass Disable */
/****************************************************/
int _8a361_get_lan_by_pass( int slot_no);
/****************************************************/
/* Get CPLD Status Of SLOT( 1 ~ 3)   */
/* return 1 : slot exit and have CPLD Bypass Function   
          0 : slot not exit and have not CPLD Bypass Function */
int _8a361_get_slot_status( int slot_no);

/****************************************************/
/* hl:  LED ON = 0   LED OFF = 1                    */
int _8a361_control_led(int ledno);
/****************************************************/
/* read the GPIO SWITCH BUTTON with JP5 setting	    */
/* Return 1, Default(Non pressed)                   */
/* Return 0, pressed/clicked                        */
int _8a361_read_bt1( void); //
int _8a361_read_bt2( void); //
/****************************************************/
/* int scale : input time scale select 0:sec 1:min  */
/* timeout: range 0~255	                            */
/* Return -1 ,WDT enable failure                    */
/* otherwise, WDT enable success                    */
int _8a361_WDT_enable(unsigned char scale, unsigned char timeout);
/****************************************************/
/* disable the WDT timer                            */
int _8a361_WDT_disable(void);
/****************************************************/
/* reload the WDT timer                             */
int _8a361_WDT_reload(void);
/****************************************************/
/* read the WDT current setting value               */
/* return -1, the WDT not setting/enable yet        */
/* otherwise, the value store in *sec               */
int _8a361_read_WDT_config(unsigned int *time);
