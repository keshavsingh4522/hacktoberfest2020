package com.example.dicegame

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.ImageView
import android.widget.TextView
import android.widget.Toast


class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        rollDice()
        val rollbutton: Button = findViewById(R.id.button)
        rollbutton.setOnClickListener {
            //val t = Toast.makeText(this, "Dice Rolled", Toast.LENGTH_SHORT)
            //t.show()
            rollDice()
        }
    }

    private fun rollDice() {
        val dice1 = Dice(6)
        val diceRoll = dice1.roll()
        val diceImage: ImageView = findViewById(R.id.imageView)
        //diceImage.setImageResource(R.drawable.dice_1)
        val drawableResource = when (diceRoll) {
            1 -> R.drawable.dice_1
            2 -> R.drawable.dice_2
            3 -> R.drawable.dice_3
            4 -> R.drawable.dice_4
            5 -> R.drawable.dice_5
            else -> R.drawable.dice_6
        }
        diceImage.setImageResource(drawableResource)
        diceImage.contentDescription=diceRoll.toString()
//        val dice2 = Dice(6)
//        val diceRoll2 = dice2.roll()
//        val resultTextView2: TextView = findViewById(R.id.dice2)
//        resultTextView2.text=diceRoll2.toString()
    }
}

class Dice(private val numSides: Int) {
    fun roll(): Int {
        return (1..numSides).random()
    }
}