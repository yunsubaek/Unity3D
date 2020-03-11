using UnityEngine;
using System.Collections.Generic;

public class test : MonoBehaviour
{
    void Awake()
    {
        //코루틴 사용(함수명,시간지날지말지 결정,false:씬 전환시 종료,true:잔존
        CoroutineManager.Instance.Register(chk(), TimerType.Unity, false);
        //에셋번들 로드
        ArchiveLoader loader = new ArchiveLoader();

        loader.Initialize(() =>
        {
            loader.LoadAssetBundles(() =>
            {
            });
        });
    }
    //코루틴 함수
    IEnumerator<CoroutinePhase> chk()
    {
        //에셋or로컬에서 가져온 프리팹을 생성
        UIBase temp = AssetManager.UI.Retrieve("MyUI");
        temp.name = "1";
        temp.gameObject.transform.position = new Vector3(0.5f, 0.5f, 0.5f);
        //지정한 시간
        yield return Suspend.Do(1.0f);
        //한 프레임
        //yield return Suspend.OneFrame();

        AssetManager.UI.Retrieve("MyUI");
        yield return Suspend.Do(1.0f);

        AssetManager.UI.Retrieve("MyUI");
        yield return Suspend.Do(1.0f);

        AssetManager.UI.Retrieve("MyUI");
        yield return Suspend.Do(3.0f);

        AssetManager.UI.DestroyAllAsset();
    } 
}
