using UnityEngine;

public class Test : MonoBehaviour
{
    public InputModule m_module;
    private InputManager m_inputManager;

    void Start()
    {
        m_inputManager = new InputManager(m_module);
    }

    void Update()
    {
        m_inputManager.Update();

        if(m_inputManager.IsInput(eInputCommand.Fire1))
        {
            Debug.Log("test");
        }

        m_inputManager.GetGroupInputs(eInputGroup.Move, (eInputCommand command) =>
        {
            switch (command)
            {
                case eInputCommand.Forward:
                    Debug.Log("앞");
                    break;
                case eInputCommand.Backward:
                    Debug.Log("뒤");
                    break;
                case eInputCommand.Left:
                    Debug.Log("왼");
                    break;
                case eInputCommand.Right:
                    Debug.Log("오");
                    break;
            }
        });
    }
}
