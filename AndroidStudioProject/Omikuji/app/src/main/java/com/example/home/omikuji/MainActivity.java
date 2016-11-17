package com.example.home.omikuji;

import android.graphics.Color;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import java.util.Random;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void getResult(View view){
        TextView tv = (TextView)findViewById(R.id.displayResult) ;
        Random randomGenerator = new Random();
        String[] result = {"大吉", "小吉", "凶"};
        int num = randomGenerator.nextInt(result.length);
        if(num == 0){
            tv.setTextColor(Color.RED);
        }else if(num == 2){
            tv.setTextColor(Color.BLUE);
        }else{
            tv.setTextColor(Color.BLACK);
        }
        tv.setText(result[num]);
    }
}
