using UnityEngine;
using System.Collections;

public class Manager : MonoBehaviour
{
    static Manager instance = null;
    public static Manager Instance //싱글톤
    {
        get
        {
            if (instance == null)
            {
                instance = FindObjectOfType(typeof(Manager)) as Manager;
                if (instance == null)
                {
                    GameObject obj = new GameObject("Manager");
                    instance = obj.AddComponent(typeof(Manager)) as Manager;
                    //객체를 찾을 수 없어서 자동으로 생성
                }
            }
            return instance;
        }
    }
}
