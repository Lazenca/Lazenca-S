package com.greycheatinglab;

import android.app.Activity;
import android.os.Bundle;

public class LazencaS extends Activity{

	static{
		System.loadLibrary("LoadEngine");
		System.loadLibrary("LazencaS");
	}
	
	@Override
	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
	}
}
