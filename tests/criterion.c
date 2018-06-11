/*
** EPITECH PROJECT, 2018
** criterion.c
** File description:
** Criterion testing file
*/

#include <criterion/criterion.h>
#include "main.h"
#include "my.h"


Test(check_for_args, ac_fail)
{
	cr_assert_neq(check_for_args(1), 1);
}
