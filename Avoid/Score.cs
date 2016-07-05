using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class Score : MonoBehaviour
{
    Text t;
    public int num;
    // Use this for initialization
    void Start()
    {
        Spawner.score = 0;
        t = GetComponent<Text>();
    }

    // Update is called once per frame
    void Update()
    {
        num = Spawner.score - 1;
        if (num > 0)
        {
            t.text = "" + num;
            print("Score = " + num);
        }
        else
        {
            t.text = "0";
            print("Score = 0");
        }
    }
}
