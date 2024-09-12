<?php

function formatNumberToCC(int|string $number): string
{
    $number = (string) $number;
    if (!preg_match('/^\d{16}$/', $number)) {
        return;
    }

    return join(' ', str_split($number, 4));
};