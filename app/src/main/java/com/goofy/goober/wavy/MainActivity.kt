package com.goofy.goober.wavy

import android.os.Bundle
import android.view.MotionEvent
import androidx.appcompat.app.AppCompatActivity
import com.goofy.goober.wavy.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        startEngine()
    }

    override fun onTouchEvent(event: MotionEvent): Boolean {
        touchEvent(event.action)
        return super.onTouchEvent(event)
    }

    override fun onDestroy() {
        stopEngine()
        super.onDestroy()
    }

    private external fun touchEvent(action: Int)

    private external fun startEngine()

    private external fun stopEngine()

    companion object {
        // Used to load the 'wavy' library on application startup.
        init {
            System.loadLibrary("wavy")
        }
    }
}
