using UnityEngine;

public class UIEnemyHP
{
    [SerializeField]
    private     GameObject      bar;
    void Start()
    {
        canvasRectT = bar.transform.root.GetComponent<RectTransform>();
    }

    void Update()
    {
        bar.GetComponentInParent<UIBase>().GetComponent<RectTransform>().position = target.position;
        //bar.GetComponentInParent<UIBase>().GetComponent<RectTransform>().position = new Vector3(target.position.x, target.position.y + 0.5f, target.position.z);
    }
}
