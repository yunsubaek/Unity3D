using UnityEngine;
using System.Collections;

public class Enemy : MonoBehaviour
{
    public RectTransform canvasRectT;
    public GameObject healthBar;
    GameObject bar;

    void Start()
    {
        bar = Instantiate(healthBar);
        //bar.transform.parent = canvasRectT.transform;
        //부모를 기준으로 할것인지 캔버스를 기준으로 할것인지에 따라 구분
        //bar.transform.SetParent(canvasRectT.transform, true);
        //bar.transform.SetParent(canvasRectT.transform);
        bar.transform.SetParent(canvasRectT.transform, false);
    }
    void Update()
    {
        Vector2 screenPoint = RectTransformUtility.WorldToScreenPoint(Camera.main, transform.position);
        bar.GetComponent<RectTransform>().anchoredPosition = screenPoint - canvasRectT.sizeDelta / 2f;
    }
}
