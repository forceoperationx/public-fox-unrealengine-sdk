package co.cyberz.fox.support.ue;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;

import co.cyberz.fox.Fox;
import co.cyberz.util.string.StringUtil;

public class IntentReceiverActivity extends Activity {

  @Override
  protected void onNewIntent(Intent intent) {
    super.onNewIntent(intent);
    setIntent(intent);
  }

  @Override
  public void onResume() {
    super.onResume();
    Fox.trackDeeplinkLaunch(this);
    startLaunchActivity();
  }

  private void startLaunchActivity() {
    Intent i = getIntent();
    Uri uri = i.getData();
    Bundle bundle = i.getExtras();

    String packageName = getPackageName();
    try {
      Intent intent = getPackageManager().getLaunchIntentForPackage(packageName);
      if (uri != null) intent.setData(uri);
      if (bundle != null) intent.putExtras(bundle);
      this.startActivity(intent);
      this.finish();
    } catch (Exception e) {
      e.printStackTrace();
      openMarketLaunchActivity(packageName);
    }
  }

  private void openMarketLaunchActivity() {
    try {
      Intent intent = this.getPackageManager().getLaunchIntentForPackage("com.android.vending");
      this.startActivity(intent);
    } catch (Exception e) {
      e.printStackTrace();
    } finally {
      this.finish();
    }
  }

  private void openMarketLaunchActivity(String packageName) {
    if (StringUtil.isEmpty(packageName)) {
      openMarketLaunchActivity();
      return;
    }
    try {
      Uri uri = Uri.parse("market://details?id=" + packageName);
      Intent intent = new Intent(Intent.ACTION_VIEW, uri);
      this.startActivity(intent);
    } catch (Exception e) {
      e.printStackTrace();
    } finally {
      this.finish();
    }
  }
}
