
#ifndef TIM_H_
#define TIM_H_

void tim2_1hz_init(void);
void tim2_PA5_output_compare(void);
void tim3_PA6_input_capture(void);

#define SR_UIF (1U<<0)
#define CC1_IF (1U<<1)


#endif /* TIM_H_ */
