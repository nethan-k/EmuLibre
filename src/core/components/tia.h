#pragma once

#include <cstdint>

class TIA {
	public:
		TIA();
		~TIA();

		/*
		 * i know technically the tia doesn't
		 * have any memory, it's just a bunch of
		 * registers (i think), but i believe that
		 * this would be the most straight
		 * forward approach. the other approach
		 * i can think of is by creating individual
		 * variables for each register, which 
		 * i think is an ugly approach.
		*/

		uint8_t mem[0x3d];		

		void clock();
		uint8_t read(uint16_t addr);
		void write(uint16_t addr, uint8_t val);

		enum REGISTER_NAMES {

			/* color registers */
			COLUP0 = 0x06, /* player 0 sprite & missile color */
			COLUP1 = 0x07, /* player 1 sprite & missile color */
			COLUPF = 0x08, /* playfield color */
			COLUBK = 0x09, /* background color */

			/* playfield registers */
			PF0 = 0x0d, /* playfield 0, drawing order: bits 4..7 */
			PF1 = 0x0e, /* playfield 1, drawing order: bits 7..0 */
			PF2 = 0x0f, /* playfield 2, drawing order: bits 0..7 */

			/* player 0 sprite registers */
			NUMSIZ0 = 0x03, /* number & size of player 0 sprite */
			REFP0 = 0x0b, /* reflect player 0 sprite (draw bits in reverse order) */
			GRP0 = 0x0b, /* bitmap for player 0 sprite */
			HMP0 = 0x20, /* horizontal motion for player 0 sprite (used for positioning) */
			VDELP0 = 0x20, /* delay drawing player 0 sprite for 1 scanline if set */
			RESP0 = 0x10, /* STROBE!!, resets position of player 0 based on current scanline position */

			/* player 1 sprite registers */
			NUMSIZ1 = 0x04, /* nuber & size of player 1 sprite */
			REFP1 = 0x0c, /* reflect player 1 sprite (draw bits in reverse order) */
			GRP1 = 0x1c, /* bitmap for player 1 sprite */
			HMP1 = 0x21, /* horizontal motion for player 0 sprite (used for positioning) */
			VDELP1 = 0x26, /* delay drawing player 1 sprite for 1 scanline if set */
			RESP1 = 0x11, /* STROBE!!, resets position of player 0 based on current scanline position */

			/* missle 0 sprites */
			ENAM0 = 0x1d, /* enable or disable the missile 0 sprite */
			HMM0 = 0x22, /* horizontal motion for sprite (used for positioning) */
			RESMP0 = 0x28, /* reset missle 0 to middle of player location */
			RESM0 = 0x12, /* STROBE!!, reset missile 0 position based on current scanline position */
			
			/* missle 1 sprite */
			ENAM1 = 0x1e, /* enable or disable the missile 1 sprite */
			HMM1 = 0x23, /* horizontal motion for missile 1 sprite (used for positioning) */
			RESMP1 = 0x29, /* reset missile 1 to middle of player location */
			RESM1 = 0x13, /* STROBE!!, reset missile 1 position based on current scanline position */

			/* ball sprite */
			CTRLPF = 0x0a, /* control playfield ball size and collisions */
			ENAMBL = 0x1f, /* enable or disable ball sprite */
			HMBL = 0x24, /* horizontal motion for sprite (used for positioning) */
			VDELBL = 0x27 /* delay drawing sprite for 1 scanline if set */
		};
};
