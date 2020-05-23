//
// Created by Dima on 23.05.2020.
//

#ifndef TICKET_SPIN_ASM_H
#define TICKET_SPIN_ASM_H

#pragma once

# define cpu_relax() asm volatile ("pause" ::: "memory");

#endif //TICKET_SPIN_ASM_H
