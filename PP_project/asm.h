//
// Created by Dima on 23.05.2020.
//

#ifndef PP_PROJECT_ASM_H
#define PP_PROJECT_ASM_H

#pragma once

# define cpu_relax() asm volatile ("pause" ::: "memory");

#endif //PP_PROJECT_ASM_H
