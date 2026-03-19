#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <bitset>

#include "atari2600_bus.h"

class Atari2600Bus;

class CPU6502 {
	public:

		CPU6502();
		~CPU6502();

		Atari2600Bus* bus = nullptr;

		/* internal registers */
		uint8_t a = 0x70;	/* accumulator */
		uint8_t x = 0x00;	/* x index register */
		uint8_t y = 0x00;	/* y index register */
		uint8_t sp = 0x00;	/* stack pointer */
		uint8_t sr = 0x00;	/* status register */
		uint16_t pc = 0x0000;	/* program counter */

		uint8_t fetched = 0x00;		/* input value to alu */
		uint16_t addr = 0x00;		/* temp address variable */
		uint8_t opcode = 0x00;		/* current opcode */
		uint8_t cycles = 0x00;		/* no. of cycles remaining */

		enum FLAGS {
			C = (1 << 0),	/* carry */
			Z = (1 << 1),	/* zero */
			I = (1 << 2),	/* disable interrupts */
			D = (1 << 3),	/* decimal mode	*/
			B = (1 << 4),	/* (no CPU effect) if b is pushed by irq || nmi, b = 0; if b is pushed by brk || php, b = 1*/
			U = (1 << 5),	/* (no CPU effect) */
			V = (1 << 6),	/* overflow */
			N = (1 << 7),	/* negative */
		};

		struct instr {
			std::string name;
			uint8_t (CPU6502::*op)(void) = nullptr;
			uint8_t (CPU6502::*am)(void) = nullptr;
			uint8_t cycles = 0;
		};

		std::vector<instr>  lookup;	/* lookup table for opcodes, operates, addressing modes, and cycles */

		/* cpu signals */
		void reset();	/* reset signal */
		void irq();	/* interrupt request */
		void nmi();	/* non-maskable interrupt */
		void clock();	/* clock signal */


		uint8_t get_flag(FLAGS f);
		void set_flag(FLAGS f, bool v);

		uint8_t fetch();

		/* addressing modes */
		uint8_t am_abs();	/* absolute */
		uint8_t am_abx();	/* absolute x-indexed */
		uint8_t am_aby();	/* absolute y-indexed */
		uint8_t am_imm();	/* immediate */
		uint8_t am_imp();	/* implied */
		uint8_t am_ind();	/* indirect */
		uint8_t am_izx();	/* indirect x-indexed */
		uint8_t am_izy();	/* indirect y-indexed */
		uint8_t am_rel(); 	/* relative */
		uint8_t am_zpg();	/* zero-page */
		uint8_t am_zpx();	/* zero-page x-indexed */
		uint8_t am_zpy();	/* zero-page y-indexed */

		/* instructions */
		uint8_t op_adc();	/* add w/ carry 			*/
		uint8_t op_and();	/* and (w/ accumulator) 		*/
		uint8_t op_asl();	/* arithmetic shift left 		*/
		uint8_t op_bcc();	/* branch on carry clear 		*/
		uint8_t op_bcs();	/* branch on carry set 			*/
		uint8_t op_beq();	/* branch on equal (zero set) 		*/
		uint8_t op_bit();	/* bit test 				*/
		uint8_t op_bmi();	/* branch on minus (negative set) 	*/
		uint8_t op_bne();	/* branch on not equal (zero clear) 	*/
		uint8_t op_bpl();	/* branch on plus (negative clear) 	*/
		uint8_t op_brk();	/* break / interrupt 			*/
		uint8_t op_bvc();	/* branch on overflow clear 		*/
		uint8_t op_bvs();	/* branch on overflow set 		*/
		uint8_t op_clc();	/* clear carry 				*/
		uint8_t op_cld();	/* clear decimal 			*/
		uint8_t op_cli();	/* clear interrupt disable 		*/
		uint8_t op_clv();	/* clear overflow 			*/
		uint8_t op_cmp();	/* compare (with accumulator) 		*/
		uint8_t op_cpx();	/* compare with X			*/
		uint8_t op_cpy();	/* compare with Y			*/
		uint8_t op_dec();	/* decrement				*/
		uint8_t op_dex();	/* decrement X				*/
		uint8_t op_dey();	/* decrement Y				*/
		uint8_t op_eor();	/* exclusive or (with accumulator)	*/
		uint8_t op_inc();	/* increment				*/
		uint8_t op_inx();	/* increment X				*/
		uint8_t op_iny();	/* increment Y				*/
		uint8_t op_jmp();	/* jump					*/
		uint8_t op_jsr();	/* jump subroutine			*/
		uint8_t op_lda();	/* load accumulator			*/
		uint8_t op_ldx();	/* load X				*/
		uint8_t op_ldy();	/* load Y				*/
		uint8_t op_lsr();	/* logical shift right			*/
		uint8_t op_nop();	/* no operation				*/
		uint8_t op_ora();	/* or with accumulator			*/
		uint8_t op_pha();	/* push accumulator			*/
		uint8_t op_php();	/* push processor status (SR)		*/
		uint8_t op_pla();	/* pull accumulator			*/
		uint8_t op_plp();	/* pull processor status (SR)		*/
		uint8_t op_rol();	/* rotate left				*/
		uint8_t op_ror();	/* rotate right				*/
		uint8_t op_rti();	/* return from interrupt		*/
		uint8_t op_rts();	/* return from subroutine		*/
		uint8_t op_sbc();	/* subtract with carry			*/
		uint8_t op_sec();	/* set carry				*/
		uint8_t op_sed();	/* set decimal				*/
		uint8_t op_sei();	/* set interrupt disable		*/
		uint8_t op_sta();	/* store accumulator			*/
		uint8_t op_stx();	/* store X				*/
		uint8_t op_sty();	/* store Y				*/
		uint8_t op_tax();	/* transfer accumulator to X		*/
		uint8_t op_tay();	/* transfer accumulator to Y		*/
		uint8_t op_tsx();	/* transfer stack pointer to X		*/
		uint8_t op_txa();	/* transfer X to accumulator		*/
		uint8_t op_txs();	/* transfer X to stack pointer		*/
		uint8_t op_tya();	/* transfer Y to accumulator		*/
		uint8_t op_xxx();	/* illegal opcode/unimplemented		*/
};
